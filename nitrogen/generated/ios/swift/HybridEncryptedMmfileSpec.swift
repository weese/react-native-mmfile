///
/// HybridEncryptedMmfileSpec.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/// See ``HybridEncryptedMmfileSpec``
public protocol HybridEncryptedMmfileSpec_protocol: HybridObject, HybridMmfileSpec_protocol {
  // Properties
  

  // Methods
  
}

/// See ``HybridEncryptedMmfileSpec``
public class HybridEncryptedMmfileSpec_base: HybridMmfileSpec_base {
  private weak var cxxWrapper: HybridEncryptedMmfileSpec_cxx? = nil
  public override func getCxxWrapper() -> HybridEncryptedMmfileSpec_cxx {
  #if DEBUG
    guard self is HybridEncryptedMmfileSpec else {
      fatalError("`self` is not a `HybridEncryptedMmfileSpec`! Did you accidentally inherit from `HybridEncryptedMmfileSpec_base` instead of `HybridEncryptedMmfileSpec`?")
    }
  #endif
    if let cxxWrapper = self.cxxWrapper {
      return cxxWrapper
    } else {
      let cxxWrapper = HybridEncryptedMmfileSpec_cxx(self as! HybridEncryptedMmfileSpec)
      self.cxxWrapper = cxxWrapper
      return cxxWrapper
    }
  }
}

/**
 * A Swift base-protocol representing the EncryptedMmfile HybridObject.
 * Implement this protocol to create Swift-based instances of EncryptedMmfile.
 * ```swift
 * class HybridEncryptedMmfile : HybridEncryptedMmfileSpec {
 *   // ...
 * }
 * ```
 */
public typealias HybridEncryptedMmfileSpec = HybridEncryptedMmfileSpec_protocol & HybridEncryptedMmfileSpec_base
