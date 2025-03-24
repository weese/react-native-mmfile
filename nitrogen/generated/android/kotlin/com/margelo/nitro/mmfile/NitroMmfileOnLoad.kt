///
/// NitroMmfileOnLoad.kt
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

package com.margelo.nitro.mmfile

import android.util.Log

internal class NitroMmfileOnLoad {
  companion object {
    private const val TAG = "NitroMmfileOnLoad"
    private var didLoad = false
    /**
     * Initializes the native part of "NitroMmfile".
     * This method is idempotent and can be called more than once.
     */
    @JvmStatic
    fun initializeNative() {
      if (didLoad) return
      try {
        Log.i(TAG, "Loading NitroMmfile C++ library...")
        System.loadLibrary("NitroMmfile")
        Log.i(TAG, "Successfully loaded NitroMmfile C++ library!")
        didLoad = true
      } catch (e: Error) {
        Log.e(TAG, "Failed to load NitroMmfile C++ library! Is it properly installed and linked? " +
                    "Is the name correct? (see `CMakeLists.txt`, at `add_library(...)`)", e)
        throw e
      }
    }
  }
}
