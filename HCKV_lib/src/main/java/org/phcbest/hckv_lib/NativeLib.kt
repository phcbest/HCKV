package org.phcbest.hckv_lib

class NativeLib {

    /**
     * A native method that is implemented by the 'hckv_lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'hckv_lib' library on application startup.
        init {
            System.loadLibrary("hckv_lib")
        }
    }
}