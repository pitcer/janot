import org.gradle.internal.jvm.Jvm

plugins {
	`cpp-library`
}

library {
	linkage.set(listOf(Linkage.SHARED))
	targetMachines.set(listOf(machines.linux.x86_64))
	val currentJvm = Jvm.current()
	val javaHome = currentJvm.javaHome
	binaries.configureEach {
		compileTask.get().apply {
			source.from(fileTree("dir" to "src", "include" to "**/*.c"))
			publicHeaders.from(file("src"))
			privateHeaders.from(file("src"))
			compilerArgs.addAll(
				"-xc",
				"-std=c11",
				"-Wall",
				"-Werror",
				"-Wfloat-equal",
				"-Wundef",
				"-Wshadow",
				"-Wpointer-arith",
				"-Wcast-align",
				"-Wstrict-prototypes",
				"-Wstrict-overflow=5",
				"-Wwrite-strings",
				"-Wcast-qual",
				"-Wswitch-default",
				"-Wswitch-enum",
				"-Wconversion",
				"-Wunreachable-code",
				"-ftrapv",
				"-fverbose-asm",
				"-finstrument-functions",
				"-Os",
				"-pthread"
			)
			includes.from(
				"$javaHome/include",
				"$javaHome/include/linux",
				"/usr/include/gdk-pixbuf-2.0",
				"/usr/include/glib-2.0",
				"/usr/lib/glib-2.0/include",
				"/usr/lib/libffi-3.2.1/include",
				"/usr/include/libmount",
				"/usr/include/blkid"
			)
		}
		if (this is CppSharedLibrary) {
			linkTask.get().apply {
				libs.from(
					"/usr/lib/libnotify.so",
					"/usr/lib/libgdk_pixbuf-2.0.so",
					"/usr/lib/libgio-2.0.so",
					"/usr/lib/libgobject-2.0.so",
					"/usr/lib/libglib-2.0.so"
				)
			}
		}
	}
}

tasks.register("generateHeaders") {
	doLast {
		exec {
			val janotPath = "${project(":janot-jvm").projectDir}/src/main/java/pl/pitcer/janot"
			commandLine("javac", "-h", "src",
				"$janotPath/notify/NativeNotification.java",
				"$janotPath/notify/NativeNotify.java",
				"$janotPath/notify/NotificationUrgency.java"
			)
		}
	}
}
