///
/// HybridMmfileFactorySpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridMmfileFactorySpec.hpp"

namespace margelo::nitro::mmfile {

  void HybridMmfileFactorySpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("openMmfile", &HybridMmfileFactorySpec::openMmfile);
      prototype.registerHybridMethod("openEncryptedMmfile", &HybridMmfileFactorySpec::openEncryptedMmfile);
    });
  }

} // namespace margelo::nitro::mmfile
