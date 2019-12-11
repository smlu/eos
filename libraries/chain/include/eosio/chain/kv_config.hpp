#pragma once

#include <fc/reflect/reflect.hpp>
#include <cstdint>

namespace eosio { namespace chain {

   /**
    * @brief limits for a kv database.
    *
    * Each database (ram or disk, currently) has its own limits for these parameters.
    * The key and value limits apply when adding or modifying elements.  They may be reduced
    * below existing database entries.
    */
   struct kv_database_config {
      std::uint32_t max_key_size;   ///< the maximum size in bytes of a key
      std::uint32_t max_value_size; ///< the maximum size in bytes of a value
      std::uint32_t max_iterators;  ///< the maximum number of iterators that a contract can have simultaneously.
   };
   inline bool operator==(const kv_database_config& lhs, const kv_database_config& rhs) {
      return lhs.max_key_size == rhs.max_key_size && lhs.max_value_size == rhs.max_value_size;
   }
   inline bool operator!=(const kv_database_config& lhs, const kv_database_config& rhs) {
      return !(lhs == rhs);
   }

   struct kv_config {
      kv_database_config kvram;
      kv_database_config kvdisk;
   };

   inline bool operator==(const kv_config& lhs, const kv_config& rhs) {
      return lhs.kvram == rhs.kvram && lhs.kvdisk == rhs.kvdisk;
   }
   inline bool operator!=(const kv_config& lhs, const kv_config& rhs) {
      return !(lhs == rhs);
   }

}}

FC_REFLECT(eosio::chain::kv_database_config, (max_key_size)(max_value_size)(max_iterators))
FC_REFLECT(eosio::chain::kv_config, (kvram)(kvdisk))
