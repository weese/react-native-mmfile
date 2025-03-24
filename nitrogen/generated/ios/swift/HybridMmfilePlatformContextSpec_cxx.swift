///
/// HybridMmfilePlatformContextSpec_cxx.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A class implementation that bridges HybridMmfilePlatformContextSpec over to C++.
 * In C++, we cannot use Swift protocols - so we need to wrap it in a class to make it strongly defined.
 *
 * Also, some Swift types need to be bridged with special handling:
 * - Enums need to be wrapped in Structs, otherwise they cannot be accessed bi-directionally (Swift bug: https://github.com/swiftlang/swift/issues/75330)
 * - Other HybridObjects need to be wrapped/unwrapped from the Swift TCxx wrapper
 * - Throwing methods need to be wrapped with a Result<T, Error> type, as exceptions cannot be propagated to C++
 */
public class HybridMmfilePlatformContextSpec_cxx {
  /**
   * The Swift <> C++ bridge's namespace (`margelo::nitro::mmfile::bridge::swift`)
   * from `NitroMmfile-Swift-Cxx-Bridge.hpp`.
   * This contains specialized C++ templates, and C++ helper functions that can be accessed from Swift.
   */
  public typealias bridge = margelo.nitro.mmfile.bridge.swift

  /**
   * Holds an instance of the `HybridMmfilePlatformContextSpec` Swift protocol.
   */
  private var __implementation: any HybridMmfilePlatformContextSpec

  /**
   * Holds a weak pointer to the C++ class that wraps the Swift class.
   */
  private var __cxxPart: bridge.std__weak_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_

  /**
   * Create a new `HybridMmfilePlatformContextSpec_cxx` that wraps the given `HybridMmfilePlatformContextSpec`.
   * All properties and methods bridge to C++ types.
   */
  public init(_ implementation: any HybridMmfilePlatformContextSpec) {
    self.__implementation = implementation
    self.__cxxPart = .init()
    /* no base class */
  }

  /**
   * Get the actual `HybridMmfilePlatformContextSpec` instance this class wraps.
   */
  @inline(__always)
  public func getHybridMmfilePlatformContextSpec() -> any HybridMmfilePlatformContextSpec {
    return __implementation
  }

  /**
   * Casts this instance to a retained unsafe raw pointer.
   * This acquires one additional strong reference on the object!
   */
  public func toUnsafe() -> UnsafeMutableRawPointer {
    return Unmanaged.passRetained(self).toOpaque()
  }

  /**
   * Casts an unsafe pointer to a `HybridMmfilePlatformContextSpec_cxx`.
   * The pointer has to be a retained opaque `Unmanaged<HybridMmfilePlatformContextSpec_cxx>`.
   * This removes one strong reference from the object!
   */
  public class func fromUnsafe(_ pointer: UnsafeMutableRawPointer) -> HybridMmfilePlatformContextSpec_cxx {
    return Unmanaged<HybridMmfilePlatformContextSpec_cxx>.fromOpaque(pointer).takeRetainedValue()
  }

  /**
   * Gets (or creates) the C++ part of this Hybrid Object.
   * The C++ part is a `std::shared_ptr<margelo::nitro::mmfile::HybridMmfilePlatformContextSpec>`.
   */
  public func getCxxPart() -> bridge.std__shared_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_ {
    let cachedCxxPart = self.__cxxPart.lock()
    if cachedCxxPart.__convertToBool() {
      return cachedCxxPart
    } else {
      let newCxxPart = bridge.create_std__shared_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_(self.toUnsafe())
      __cxxPart = bridge.weakify_std__shared_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_(newCxxPart)
      return newCxxPart
    }
  }

  

  /**
   * Get the memory size of the Swift class (plus size of any other allocations)
   * so the JS VM can properly track it and garbage-collect the JS object if needed.
   */
  @inline(__always)
  public var memorySize: Int {
    return MemoryHelper.getSizeOf(self.__implementation) + self.__implementation.memorySize
  }

  // Properties
  

  // Methods
  @inline(__always)
  public final func getBaseDirectory() -> bridge.Result_std__string_ {
    do {
      let __result = try self.__implementation.getBaseDirectory()
      let __resultCpp = std.string(__result)
      return bridge.create_Result_std__string_(__resultCpp)
    } catch (let __error) {
      let __exceptionPtr = __error.toCpp()
      return bridge.create_Result_std__string_(__exceptionPtr)
    }
  }
  
  @inline(__always)
  public final func getAppGroupDirectory() -> bridge.Result_std__optional_std__string__ {
    do {
      let __result = try self.__implementation.getAppGroupDirectory()
      let __resultCpp = { () -> bridge.std__optional_std__string_ in
        if let __unwrappedValue = __result {
          return bridge.create_std__optional_std__string_(std.string(__unwrappedValue))
        } else {
          return .init()
        }
      }()
      return bridge.create_Result_std__optional_std__string__(__resultCpp)
    } catch (let __error) {
      let __exceptionPtr = __error.toCpp()
      return bridge.create_Result_std__optional_std__string__(__exceptionPtr)
    }
  }
}
