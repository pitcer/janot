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
			compilerArgs.addAll(listOf("-xc", "-std=c11", "-Wall", "-Werror", "-Os"))
			includes.from(files("$javaHome/include", "$javaHome/include/linux"))
		}
	}
}

tasks.register("generateHeaders") {
	doLast {
		exec {
			commandLine("javac", "-h", "src", "${project(":janot-jvm").projectDir}/src/main/java/pl/pitcer/janot/Janot.java")
		}
	}
}
