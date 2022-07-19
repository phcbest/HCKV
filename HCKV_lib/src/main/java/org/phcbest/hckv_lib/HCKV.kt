package org.phcbest.hckv_lib

import android.content.Context
import android.util.Log

/**
 *
 */
class HCKV {
    private var nativeHandle: Long = 0L

    constructor(handle: Long) {
        nativeHandle = handle
    }

    companion object {
        private const val TAG = "HCKV"

        private var rootDir: String? = null

        /**
         * 进行初始化
         */
        public fun initialize(context: Context): String {
            var root = context.filesDir.absolutePath + "/hckv"
            //加载库
            System.loadLibrary("hckv_lib")

            nInitialize(root)
            rootDir = root

            return rootDir!!
        }

        /**
         * 获得默认HCKV实例
         */
        public fun defaultEZKV(): HCKV? {
            if (rootDir == null) {
                throw IllegalStateException("HCKV not initialized")
            }
            val handle = nGetDefaultHCKV()
            if (handle == 0L) {
                return null
            }
            Log.d(TAG, "defaultEZKV 获取默认HCKV: $handle")
            return HCKV(handle)
        }


        public fun pageSize(): Long {
            return nPageSize()
        }

        //-----native方法-----
        private external fun nInitialize(rootDir: String)
        private external fun nGetDefaultHCKV(): Long
        private external fun nPageSize(): Long
    }

    fun encode(key: String, value: Int): Boolean {
        return nEncodeInt(nativeHandle, key, value)
    }

    fun decode(key: String, defaultValue: Int): Int {
        return nDecodeInt(nativeHandle, key, defaultValue)
    }

    fun encode(key: String, value: String): Boolean {
        return nEncodeString(nativeHandle, key, value)
    }

    fun decode(key: String, defaultValue: String): String {
        return nDecodeString(nativeHandle, key, defaultValue)
    }

    fun removeValueFoKey(key: String) {
        return nRemoveValueForKey(nativeHandle, key)
    }

    fun toTalSize(): Long {
        return nTotalSize(nativeHandle)
    }

    fun count(): Long {
        return nCount(nativeHandle)
    }

    //-----native方法-----
    private external fun nEncodeInt(handle: Long, key: String, value: Int): Boolean
    private external fun nDecodeInt(handle: Long, key: String, defaultValue: Int): Int
    private external fun nEncodeString(handle: Long, key: String, value: String): Boolean
    private external fun nDecodeString(handle: Long, key: String, defaultValue: String): String
    private external fun nRemoveValueForKey(handle: Long, key: String)
    private external fun nTotalSize(handle: Long): Long
    private external fun nCount(handle: Long): Long

}