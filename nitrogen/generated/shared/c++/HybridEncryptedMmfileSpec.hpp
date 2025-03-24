///
/// HybridEncryptedMmfileSpec.hpp
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

// Forward declaration of `HybridMmfileSpec` to properly resolve imports.
namespace margelo::nitro::mmfile { class HybridMmfileSpec; }

#include <memory>
#include "HybridMmfileSpec.hpp"

namespace margelo::nitro::mmfile {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `EncryptedMmfile`
   * Inherit this class to create instances of `HybridEncryptedMmfileSpec` in C++.
   * You must explicitly call `HybridObject`'s constructor yourself, because it is virtual.
   * @example
   * ```cpp
   * class HybridEncryptedMmfile: public HybridEncryptedMmfileSpec {
   * public:
   *   HybridEncryptedMmfile(...): HybridObject(TAG) { ... }
   *   // ...
   * };
   * ```
   */
  class HybridEncryptedMmfileSpec: public virtual HybridObject, public virtual HybridMmfileSpec {
    public:
      // Constructor
      explicit HybridEncryptedMmfileSpec(): HybridObject(TAG) { }

      // Destructor
      ~HybridEncryptedMmfileSpec() override = default;

    public:
      // Properties
      

    public:
      // Methods
      

    protected:
      // Hybrid Setup
      void loadHybridMethods() override;

    protected:
      // Tag for logging
      static constexpr auto TAG = "EncryptedMmfile";
  };

} // namespace margelo::nitro::mmfile
