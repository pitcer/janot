/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class pl_pitcer_janot_notify_NativeNotification */

#ifndef _Included_pl_pitcer_janot_notify_NativeNotification
#define _Included_pl_pitcer_janot_notify_NativeNotification
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    newInstance
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/nio/ByteBuffer;
 */
JNIEXPORT jobject JNICALL Java_pl_pitcer_janot_notify_NativeNotification_newInstance
  (JNIEnv *, jclass, jstring, jstring, jstring);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    update
 * Signature: (Ljava/nio/ByteBuffer;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotification_update
  (JNIEnv *, jclass, jobject, jstring, jstring, jstring);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    show
 * Signature: (Ljava/nio/ByteBuffer;Ljava/lang/Object;)Z
 */
JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotification_show
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    setTimeout
 * Signature: (Ljava/nio/ByteBuffer;I)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setTimeout
  (JNIEnv *, jclass, jobject, jint);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    setCategory
 * Signature: (Ljava/nio/ByteBuffer;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setCategory
  (JNIEnv *, jclass, jobject, jstring);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    setUrgency
 * Signature: (Ljava/nio/ByteBuffer;I)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setUrgency
  (JNIEnv *, jclass, jobject, jint);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    setImageFromPixbuf
 * Signature: (Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setImageFromPixbuf
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    setHint
 * Signature: (Ljava/nio/ByteBuffer;Ljava/lang/String;Ljava/nio/ByteBuffer;)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setHint
  (JNIEnv *, jclass, jobject, jstring, jobject);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    setAppName
 * Signature: (Ljava/nio/ByteBuffer;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_setAppName
  (JNIEnv *, jclass, jobject, jstring);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    clearHints
 * Signature: (Ljava/nio/ByteBuffer;)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_clearHints
  (JNIEnv *, jclass, jobject);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    addAction
 * Signature: (Ljava/nio/ByteBuffer;Ljava/lang/String;Ljava/lang/String;Lpl/pitcer/janot/notify/NotificationCallback;)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_addAction
  (JNIEnv *, jclass, jobject, jstring, jstring, jobject);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    clearActions
 * Signature: (Ljava/nio/ByteBuffer;)V
 */
JNIEXPORT void JNICALL Java_pl_pitcer_janot_notify_NativeNotification_clearActions
  (JNIEnv *, jclass, jobject);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    close
 * Signature: (Ljava/nio/ByteBuffer;Ljava/lang/Object;)Z
 */
JNIEXPORT jboolean JNICALL Java_pl_pitcer_janot_notify_NativeNotification_close
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     pl_pitcer_janot_notify_NativeNotification
 * Method:    getClosedReason
 * Signature: (Ljava/nio/ByteBuffer;)I
 */
JNIEXPORT jint JNICALL Java_pl_pitcer_janot_notify_NativeNotification_getClosedReason
  (JNIEnv *, jclass, jobject);

#ifdef __cplusplus
}
#endif
#endif
