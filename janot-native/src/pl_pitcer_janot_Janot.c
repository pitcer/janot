#include "pl_pitcer_janot_Janot.h"

#include <stdio.h>
#include <stdbool.h>

#include "libnotify_notification.h"

JNIEXPORT void JNICALL Java_pl_pitcer_janot_Janot_helloJanot(JNIEnv* env, jclass class) {
	printf("Hello Janot!\n");
}

JNIEXPORT void JNICALL Java_pl_pitcer_janot_Janot_sendNotification(JNIEnv* env, jclass class, jstring summary, jstring body, jstring icon) {
	JNIEnv jni_environment = *env;
	const char* summary_chars = jni_environment->GetStringUTFChars(env, summary, false);
	const char* body_chars = jni_environment->GetStringUTFChars(env, body, false);
	const char* icon_chars = jni_environment->GetStringUTFChars(env, icon, false);
	send_notification(summary_chars, body_chars, icon_chars);
	jni_environment->ReleaseStringUTFChars(env, summary, summary_chars);
	jni_environment->ReleaseStringUTFChars(env, body, body_chars);
	jni_environment->ReleaseStringUTFChars(env, icon, icon_chars);
}
