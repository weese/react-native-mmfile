///
/// HybridMmfilePlatformContextSpec.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/HybridObject.hpp>)
#include <NitroModules/HybridObject.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif



#include <string>
#include <optional>

namespace margelo::nitro::mmfile {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `MmfilePlatformContext`
   * Inherit this class to create instances of `HybridMmfilePlatformContextSpec` in C++.
   * You must explicitly call `HybridObject`'s constructor yourself, because it is virtual.
   * @example
   * ```cpp
   * class HybridMmfilePlatformContext: public HybridMmfilePlatformContextSpec {
   * public:
   *   HybridMmfilePlatformContext(...): HybridObject(TAG) { ... }
   *   // ...
   * };
   * ```
   */
  class HybridMmfilePlatformContextSpec: public virtual HybridObject {
    public:
      // Constructor
      explicit HybridMmfilePlatformContextSpec(): HybridObject(TAG) { }

      // Destructor
      ~HybridMmfilePlatformContextSpec() override = default;

    public:
      // Properties
      

    public:
      // Methods
      virtual std::string getBaseDirectory() = 0;
      virtual std::optional<std::string> getAppGroupDirectory() = 0;

    protected:
      // Hybrid Setup
      void loadHybridMethods() override;

    protected:
      // Tag for logging
      static constexpr auto TAG = "MmfilePlatformContext";
  };

} // namespace margelo::nitro::mmfile
