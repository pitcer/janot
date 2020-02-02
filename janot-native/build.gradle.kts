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
				"/usr/include/blkid",
				"/usr/include/gtk-3.0",
				"/usr/include/pango-1.0",
				"/usr/include/harfbuzz",
				"/usr/include/fribidi",
				"/usr/include/freetype2",
				"/usr/include/libpng16",
				"/usr/include/cairo",
				"/usr/include/pixman-1",
				"/usr/include/gio-unix-2.0",
				"/usr/include/atk-1.0",
				"/usr/include/at-spi2-atk/2.0",
				"/usr/include/at-spi-2.0",
				"/usr/include/dbus-1.0",
				"/usr/lib/dbus-1.0/include"
			)
		}
		if (this is CppSharedLibrary) {
			linkTask.get().apply {
				libs.from(
					"/usr/lib/libnotify.so",
					"/usr/lib/libgdk_pixbuf-2.0.so",
					"/usr/lib/libgio-2.0.so",
					"/usr/lib/libgobject-2.0.so",
					"/usr/lib/libglib-2.0.so",
					"/usr/lib/libgtk-3.so",
					"/usr/lib/libgdk-3.so",
					"/usr/lib/libz.so",
					"/usr/lib/libpangocairo-1.0.so",
					"/usr/lib/libpango-1.0.so",
					"/usr/lib/libharfbuzz.so",
					"/usr/lib/libatk-1.0.so",
					"/usr/lib/libcairo-gobject.so",
					"/usr/lib/libcairo.so"
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
				"$janotPath/notify/NotificationCallback.java",
				"$janotPath/gtk/NativeGtk.java",
				"$janotPath/gtk/NativeWidget.java",
				"$janotPath/gtk/NativeWindow.java",
				"$janotPath/gtk/DestroyCallback.java"
			)
		}
	}
}
