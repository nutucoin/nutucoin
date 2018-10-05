// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, The TurtleCoin developers
// Copyright (c) 2018, The Karbo developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <iterator>
#include <fstream>

#include "Checkpoints.h"
#include "Common/StringTools.h"
#include "Common/DnsTools.h"

using namespace Logging;

namespace CryptoNote {
//---------------------------------------------------------------------------
Checkpoints::Checkpoints(Logging::ILogger &log) : logger(log, "checkpoints") {}
//---------------------------------------------------------------------------
bool Checkpoints::add_checkpoint(uint32_t height, const std::string &hash_str) {
  Crypto::Hash h = NULL_HASH;

  if (!Common::podFromHex(hash_str, h)) {
    logger(WARNING) << "Wrong hash in checkpoint for height " << height;
    return false;
  }

  if (!m_points.insert({ height, h }).second) {
    logger(WARNING) << "Checkpoint already exists.";
    return false;
  }

  m_points[height] = h;
  return true;
}
//---------------------------------------------------------------------------
bool Checkpoints::load_checkpoints_from_file(const std::string& fileName) {
	std::ifstream file(fileName);
	if (!file) {
		logger(Logging::ERROR, BRIGHT_RED) << "Could not load checkpoints file: " << fileName;
		return false;
	}
	std::string indexString;
	std::string hash;
	uint32_t height;
	while (std::getline(file, indexString, ','), std::getline(file, hash)) {
		try {
			height = std::stoi(indexString);
		} catch (const std::invalid_argument &)	{
			logger(ERROR, BRIGHT_RED) << "Invalid checkpoint file format - "
				<< "could not parse height as a number";
			return false;
		}
		if (!add_checkpoint(height, hash)) {
			return false;
		}
	}
	logger(Logging::INFO) << "Loaded " << m_points.size() << " checkpoints from "	<< fileName;
	return true;
}

//---------------------------------------------------------------------------
bool Checkpoints::is_in_checkpoint_zone(uint32_t  height) const {
  return !m_points.empty() && (height <= (--m_points.end())->first);
}
//---------------------------------------------------------------------------
bool Checkpoints::check_block(uint32_t  height, const Crypto::Hash &h,
                              bool &is_a_checkpoint) const {
  auto it = m_points.find(height);
  is_a_checkpoint = it != m_points.end();
  if (!is_a_checkpoint)
    return true;

  if (it->second == h) {
	if (height % 100 == 0) {
    logger(Logging::INFO, Logging::GREEN) 
      << "CHECKPOINT PASSED FOR HEIGHT " << height << " " << h;
	}
    return true;
  } else {
    logger(Logging::ERROR) << "CHECKPOINT FAILED FOR HEIGHT " << height
                           << ". EXPECTED HASH: " << it->second
                           << ", FETCHED HASH: " << h;
    return false;
  }
}
//---------------------------------------------------------------------------
bool Checkpoints::check_block(uint32_t  height, const Crypto::Hash &h) const {
  bool ignored;
  return check_block(height, h, ignored);
}
//---------------------------------------------------------------------------
bool Checkpoints::is_alternative_block_allowed(uint32_t  blockchain_height,
                                               uint32_t  block_height) const {
  if (0 == block_height)
    return false;

  auto it = m_points.upper_bound(blockchain_height);
  // Is blockchain_height before the first checkpoint?
  if (it == m_points.begin())
    return true;

  --it;
  uint32_t  checkpoint_height = it->first;
  return checkpoint_height < block_height;
}

std::vector<uint32_t> Checkpoints::getCheckpointHeights() const {
  std::vector<uint32_t> checkpointHeights;
  checkpointHeights.reserve(m_points.size());
  for (const auto& it : m_points) {
    checkpointHeights.push_back(it.first);
  }

  return checkpointHeights;
}

} 