#include <stdio.h>

#include "pl_pitcer_janot_Janot.h"

JNIEXPORT void JNICALL Java_pl_pitcer_janot_Janot_helloJanot(JNIEnv *env, jclass class) {
	printf("Hello Janot!\n");
}
