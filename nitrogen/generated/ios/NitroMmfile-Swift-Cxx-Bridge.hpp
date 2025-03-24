///
/// NitroMmfile-Swift-Cxx-Bridge.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

// Forward declarations of C++ defined types
// Forward declaration of `HybridEncryptedMmfileSpec` to properly resolve imports.
namespace margelo::nitro::mmfile { class HybridEncryptedMmfileSpec; }
// Forward declaration of `HybridMmfilePlatformContextSpec` to properly resolve imports.
namespace margelo::nitro::mmfile { class HybridMmfilePlatformContextSpec; }
// Forward declaration of `HybridMmfileSpec` to properly resolve imports.
namespace margelo::nitro::mmfile { class HybridMmfileSpec; }

// Forward declarations of Swift defined types
// Forward declaration of `HybridEncryptedMmfileSpec_cxx` to properly resolve imports.
namespace NitroMmfile { class HybridEncryptedMmfileSpec_cxx; }
// Forward declaration of `HybridMmfilePlatformContextSpec_cxx` to properly resolve imports.
namespace NitroMmfile { class HybridMmfilePlatformContextSpec_cxx; }
// Forward declaration of `HybridMmfileSpec_cxx` to properly resolve imports.
namespace NitroMmfile { class HybridMmfileSpec_cxx; }

// Include C++ defined types
#include "HybridEncryptedMmfileSpec.hpp"
#include "HybridMmfilePlatformContextSpec.hpp"
#include "HybridMmfileSpec.hpp"
#include <NitroModules/Result.hpp>
#include <exception>
#include <memory>
#include <optional>
#include <string>

/**
 * Contains specialized versions of C++ templated types so they can be accessed from Swift,
 * as well as helper functions to interact with those C++ types from Swift.
 */
namespace margelo::nitro::mmfile::bridge::swift {

  // pragma MARK: std::shared_ptr<margelo::nitro::mmfile::HybridMmfileSpec>
  /**
   * Specialized version of `std::shared_ptr<margelo::nitro::mmfile::HybridMmfileSpec>`.
   */
  using std__shared_ptr_margelo__nitro__mmfile__HybridMmfileSpec_ = std::shared_ptr<margelo::nitro::mmfile::HybridMmfileSpec>;
  std::shared_ptr<margelo::nitro::mmfile::HybridMmfileSpec> create_std__shared_ptr_margelo__nitro__mmfile__HybridMmfileSpec_(void* _Nonnull swiftUnsafePointer);
  void* _Nonnull get_std__shared_ptr_margelo__nitro__mmfile__HybridMmfileSpec_(std__shared_ptr_margelo__nitro__mmfile__HybridMmfileSpec_ cppType);
  
  // pragma MARK: std::weak_ptr<margelo::nitro::mmfile::HybridMmfileSpec>
  using std__weak_ptr_margelo__nitro__mmfile__HybridMmfileSpec_ = std::weak_ptr<margelo::nitro::mmfile::HybridMmfileSpec>;
  inline std__weak_ptr_margelo__nitro__mmfile__HybridMmfileSpec_ weakify_std__shared_ptr_margelo__nitro__mmfile__HybridMmfileSpec_(const std::shared_ptr<margelo::nitro::mmfile::HybridMmfileSpec>& strong) { return strong; }
  
  // pragma MARK: Result<void>
  using Result_void_ = Result<void>;
  inline Result_void_ create_Result_void_() {
    return Result<void>::withValue();
  }
  inline Result_void_ create_Result_void_(const std::exception_ptr& error) {
    return Result<void>::withError(error);
  }
  
  // pragma MARK: Result<double>
  using Result_double_ = Result<double>;
  inline Result_double_ create_Result_double_(double value) {
    return Result<double>::withValue(std::move(value));
  }
  inline Result_double_ create_Result_double_(const std::exception_ptr& error) {
    return Result<double>::withError(error);
  }
  
  // pragma MARK: std::shared_ptr<margelo::nitro::mmfile::HybridEncryptedMmfileSpec>
  /**
   * Specialized version of `std::shared_ptr<margelo::nitro::mmfile::HybridEncryptedMmfileSpec>`.
   */
  using std__shared_ptr_margelo__nitro__mmfile__HybridEncryptedMmfileSpec_ = std::shared_ptr<margelo::nitro::mmfile::HybridEncryptedMmfileSpec>;
  std::shared_ptr<margelo::nitro::mmfile::HybridEncryptedMmfileSpec> create_std__shared_ptr_margelo__nitro__mmfile__HybridEncryptedMmfileSpec_(void* _Nonnull swiftUnsafePointer);
  void* _Nonnull get_std__shared_ptr_margelo__nitro__mmfile__HybridEncryptedMmfileSpec_(std__shared_ptr_margelo__nitro__mmfile__HybridEncryptedMmfileSpec_ cppType);
  
  // pragma MARK: std::shared_ptr<margelo::nitro::mmfile::HybridMmfileSpec>
  inline std::shared_ptr<margelo::nitro::mmfile::HybridMmfileSpec> upcast_EncryptedMmfile_to_Mmfile(std::shared_ptr<margelo::nitro::mmfile::HybridEncryptedMmfileSpec> child) { return child; }
  
  // pragma MARK: std::weak_ptr<margelo::nitro::mmfile::HybridEncryptedMmfileSpec>
  using std__weak_ptr_margelo__nitro__mmfile__HybridEncryptedMmfileSpec_ = std::weak_ptr<margelo::nitro::mmfile::HybridEncryptedMmfileSpec>;
  inline std__weak_ptr_margelo__nitro__mmfile__HybridEncryptedMmfileSpec_ weakify_std__shared_ptr_margelo__nitro__mmfile__HybridEncryptedMmfileSpec_(const std::shared_ptr<margelo::nitro::mmfile::HybridEncryptedMmfileSpec>& strong) { return strong; }
  
  // pragma MARK: std::optional<std::string>
  /**
   * Specialized version of `std::optional<std::string>`.
   */
  using std__optional_std__string_ = std::optional<std::string>;
  inline std::optional<std::string> create_std__optional_std__string_(const std::string& value) {
    return std::optional<std::string>(value);
  }
  
  // pragma MARK: std::shared_ptr<margelo::nitro::mmfile::HybridMmfilePlatformContextSpec>
  /**
   * Specialized version of `std::shared_ptr<margelo::nitro::mmfile::HybridMmfilePlatformContextSpec>`.
   */
  using std__shared_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_ = std::shared_ptr<margelo::nitro::mmfile::HybridMmfilePlatformContextSpec>;
  std::shared_ptr<margelo::nitro::mmfile::HybridMmfilePlatformContextSpec> create_std__shared_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_(void* _Nonnull swiftUnsafePointer);
  void* _Nonnull get_std__shared_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_(std__shared_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_ cppType);
  
  // pragma MARK: std::weak_ptr<margelo::nitro::mmfile::HybridMmfilePlatformContextSpec>
  using std__weak_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_ = std::weak_ptr<margelo::nitro::mmfile::HybridMmfilePlatformContextSpec>;
  inline std__weak_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_ weakify_std__shared_ptr_margelo__nitro__mmfile__HybridMmfilePlatformContextSpec_(const std::shared_ptr<margelo::nitro::mmfile::HybridMmfilePlatformContextSpec>& strong) { return strong; }
  
  // pragma MARK: Result<std::string>
  using Result_std__string_ = Result<std::string>;
  inline Result_std__string_ create_Result_std__string_(const std::string& value) {
    return Result<std::string>::withValue(value);
  }
  inline Result_std__string_ create_Result_std__string_(const std::exception_ptr& error) {
    return Result<std::string>::withError(error);
  }
  
  // pragma MARK: Result<std::optional<std::string>>
  using Result_std__optional_std__string__ = Result<std::optional<std::string>>;
  inline Result_std__optional_std__string__ create_Result_std__optional_std__string__(const std::optional<std::string>& value) {
    return Result<std::optional<std::string>>::withValue(value);
  }
  inline Result_std__optional_std__string__ create_Result_std__optional_std__string__(const std::exception_ptr& error) {
    return Result<std::optional<std::string>>::withError(error);
  }

} // namespace margelo::nitro::mmfile::bridge::swift
