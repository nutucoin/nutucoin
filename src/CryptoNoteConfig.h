// Copyright (c) 2016-2018, The Nutucoin developers
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

#pragma once

#include <cstdint>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 240; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x1c3a82; // addresses start with "N"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = DIFFICULTY_TARGET * 7;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(12000000000000000000);
const uint64_t TAIL_EMISSION_REWARD                          = UINT64_C(1000000000000);
const size_t CRYPTONOTE_COIN_VERSION                         = 1;
const unsigned EMISSION_SPEED_FACTOR                         = 18;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 10000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 100000000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 100000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 12;
const uint64_t MINIMUM_FEE                                   = UINT64_C(10000000000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(10000000);
const uint64_t MAX_TX_MIXIN_SIZE                             = 20;

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 17;  // blocks
const size_t   DIFFICULTY_WINDOW_V3                          = 60;  // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;  // !!!
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 1000000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24 * 2;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 1; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1 * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 60000;
const uint32_t UPGRADE_HEIGHT_V3                             = 216000;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90; // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "nutucoin";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001aceceba0a2b40a029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210117b640d4795ab9d1f5340482454091968a8457a5522c03ed8d0464bc6ed6b791";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  49638;
const int      RPC_DEFAULT_PORT                              =  49639;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const uint32_t P2P_FAILED_ADDR_FORGET_SECONDS                = (60 * 60);     //1 hour
const uint32_t P2P_IP_BLOCKTIME                              = (60 * 60 * 24);//24 hour
const uint32_t P2P_IP_FAILS_BEFORE_BLOCK                     = 10;
const uint32_t P2P_IDLE_CONNECTION_KILL_INTERVAL             = (5 * 60);      //5 minutes

const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const char* const SEED_NODES[] = { 
  "104.236.202.12:49638",
  "104.236.239.237:49638"
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = { 
{1, "42a2a1ce58385dbfd134adcffd757514c752d9245849867fa70b24a841be78d2" },
{500,"1c9211f75a554438e877881af258cd146f6d26abe78b3912ad4aea59a91dbb30"},
{1000,"cc650e214af481263df4ca8af2aa2a3499d7e39eae138a8beb9ffbedca0bb3fe"},
{1500,"9cec27c104d749ae719772edec432b2d3e202ba99828cb99836716cee20ea807"},
{2000,"4cd3373eb0e03488876fc73f0747fdb732216bcc7c82dabd0c663e997c67905f"},
{2500,"66985e8dc122677abf7b67677c6031c2074f2ddc7211aa8e0f441c5de0e0c87f"},
{3000,"8b55ef2d5c673cc06135a53c53f37bf6cf5b2941dd37b4b0fbd9c9a3f491ffa6"},
{3500,"b45179b6af4fc83e7e4a4545f6584d0e8cfabca0bff566054296445bf7edb504"},
{4000,"14554a8af8c3ec2b42a805926b83d614b89f0e7309b452dd259bc112cbdd83b1"},
{4500,"c54e330e83d001040df3b8cd192107e7d68fa6c6c8c8462703568e56c7762abf"},
{5000,"a3424020e1f9a710faa28a0dbb3e0dca3eed0390063cfffaf946459b9ef65c2e"},
{5500,"58a96a8c8412e2f1237dcab75ae3414da28c4c32dcdab5037402801f725e9248"},
{6000,"9a6c2f04b6133a3deacaef141a53e08e74525718950c3617f7f0b918ca9e17c0"},
{6500,"798832840c8c8d856840007fbdee960c7a4eb333470e56f97636a7e08de491d5"},
{7000,"45550650e51b40713f7997f288c902f200c982a9844c4144b345da37ebcc0695"},
{7500,"edddbedb5b939151c7e5d7c4104dd6fb86e524c7770716dbb54f707decfe3f36"},
{8000,"9933ba3cf674f7fa25c08e32315dc67022f45e0edcd64c48a1ead1bd7c5a1dab"},
{8500,"1348ff7c2136610d7eb57e0d184ec48ab35afd05d9f02131569e1fefc1dd623f"},
{9000,"486293ee690b723c5ecb399a2b529c0ddeadc3eadbd341eaf63c4836c0a0787a"},
{9500,"e25140ae5a23d5ffe3513252510703f65089fca28cfc8ffb962f73b670df0869"},
{10000,"66efbded858d4cea841ed65371def7fd7239fc4179a67b129e8c0db729651f67"},
{10500,"55324be641a30da5e45e59589e380419ad103e6a60e16b22d19ad98ec1d73903"},
{11000,"59d9771198a0a3230457df0c5c687539ac5ac3ce822df748da6ecbbc07a0770a"},
{11500,"26671d9634b93f4c860d6ecba27643b6a8cf02f39feeb3245fb7effea4bbf008"},
{12000,"759d59d0a7ae1221ba022da8e931ae0d3145b79403c6f97183b7673b524b326d"},
{12500,"d7f7814a8d8b6d29271843b5b63106693fd6cd488fa0acabd6406b87929a7284"},
{13000,"fbb6b64e70eb30d3a6e3433ea5be71d8f915ac70ac6f93407efb9efd54f03fbb"},
{13500,"dd497ade573e8bd974953189a51cf700d971f4caafd0d5f4b79ca51c6fa77242"},
{14000,"618c85accfe8bdce111ae0ada468e5845ee92b2af14ab8c02f1aa16de67509f2"},
{14500,"388d0ee7e550f7435aacbce57c948853d673a1cd173be56b1e76aef11f565e78"},
{15000,"47e9e48a887135e974cfe00812c04fead892cc05dd065c4863bbbf574b17ab55"},
{15500,"fb00a5233db80cd3015cefab8a3dc925542f150ffc85ceb653b99bdc0cc4f678"},
{16000,"5a124ef0b73f49aed70897cb1250c086b6656c919233d68b3c8480a340040f26"},
{16500,"c9f6f7735a5303cb4aa35a1ab8614f49b81935f34ced69727a7535522a80c581"},
{17000,"d5d93d0a746f0d4650fa80654a0ba49af4ac3f4970f2567f153ee2a7e1013a8a"},
{17500,"3489f25baeb4f4b3a65636fafd25578770a0f0dcede84f306f71fc3cf7c95a8d"},
{18000,"b1cc26066313f20417ad509f75470821f5e21347c65390fa4f4081b241211f2b"},
{18500,"4ad2ed4ab6dad91834a9a2835529ece756a2e298ad6203e3db8502534ff47b03"},
{19000,"2959914b1fcbe9e72502ae2bffaac7dd417252466afe7ce51d126b0d4e254aaa"},
{19500,"0e91dc7e9cf89a55874b7be6c60dcaab7b4c11371e395ae18bec76fdd53ac53e"},
{20000,"ed8cd0f79a5a63e1a279c6bf787a3bb1b1b05ecae936a604818bd2a0b641f718"},
{20500,"c9ce098f91525af49b51bf1a3f0051f351df3e161270cb60cf81c9208b4b252f"},
{21000,"9cd44c7a21784676fe96e6e4bf4a012467e868897417312eb5b19b552d331a06"},
{21500,"0b32f659be66564e82f655836da8836966b4453496b554b4d592ac4e97b8b8cf"},
{22000,"6ea82e2db8aac727540ebaaf6a61c22fc944d4f6f044028bacbc4f740d042137"},
{22500,"fe53c946211ec1b5caae6104c29635738016d0f5c624bff12e995013dfc565c8"},
{23000,"56c136326081682e98ad8484658a6809168e708698898cb6b967d2bd80e86208"},
{23500,"ba48425c28116596fb5ea562f1f0e3daf1ab6f681bfeecbfdb657fddccc79081"},
{24000,"7ef7fcf477a8cf3baa3694aa549a9414f892f54d9709cbf9190fb034359cec5f"},
{24500,"a66ef2fdee2b29ee30fcf13418570891ad202dfbc79da21279f15278b3ceae66"},
{25000,"da1f39b5b862d938b3b30f368fbf543c4cee7ff4acd1dec78f17c7da68429a27"},
{25500,"ae4aa0ca57a486272a90da83d13099ed20b23b3748a89a57bb4564a51edce4eb"},
{26000,"ac3ee464c12eb9691c5a5d59adda00e2d8744a9c82555b9c8552ffe15ef81a69"},
{26500,"849fc602d04b7cb44c7ac05c136345d1ca8ecb3d3a46811b0212df57faef9d0e"},
{27000,"9c2fbcc97771079493f23a36c9cefdf1a030b5295065b2da3706c3b3678e71a7"},
{27500,"be22eaafe1e1a21815846f6f8e5695309a672da799ca6b115fd41fda58e74008"},
{28000,"35c78ee397a41015be02ca5a37c8ce89cf35e83728e9379d4f9b2797c4be2be0"},
{28500,"e6627c10ea0e3a476497cd358615b918f29a82192095b6c289360132e9dfa5e5"},
{29000,"280eb5176e9e056d623dff1fff5b5202776c9bd6867b981a1c5c964257cca8a3"},
{29500,"97b219e62f52f88fbc2c1d2bacd94d621810f9c2093bc62ea8a2f5ddb611d9ba"}
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS