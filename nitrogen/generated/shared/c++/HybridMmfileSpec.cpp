///
/// HybridMmfileSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridMmfileSpec.hpp"

namespace margelo::nitro::mmfile {

  void HybridMmfileSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("size", &HybridMmfileSpec::getSize);
      prototype.registerHybridGetter("capacity", &HybridMmfileSpec::getCapacity);
      prototype.registerHybridGetter("readOnly", &HybridMmfileSpec::getReadOnly);
      prototype.registerHybridGetter("filePath", &HybridMmfileSpec::getFilePath);
      prototype.registerHybridMethod("resize", &HybridMmfileSpec::resize);
      prototype.registerHybridMethod("clear", &HybridMmfileSpec::clear);
      prototype.registerHybridMethod("append", &HybridMmfileSpec::append);
      prototype.registerHybridMethod("write", &HybridMmfileSpec::write);
      prototype.registerHybridMethod("read", &HybridMmfileSpec::read);
    });
  }

} // namespace margelo::nitro::mmfile
