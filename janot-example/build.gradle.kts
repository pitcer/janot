plugins {
	java
	application
	id("com.github.johnrengelman.shadow") version "5.2.0"
}

dependencies {
	implementation(project(":janot-jvm"))
}

java {
	sourceCompatibility = JavaVersion.VERSION_11
	targetCompatibility = JavaVersion.VERSION_11
}

application {
	mainClassName = "pl.pitcer.janot.Main"
	applicationDefaultJvmArgs = listOf("-Djava.library.path=${project.buildDir}/libs")
}

tasks.getByName("run") {
	dependsOn.add(":janot-native:build")
	doFirst {
		copy {
			from("${project(":janot-native").buildDir}/lib/main/debug/libjanot-native.so")
			into("${project.buildDir}/libs")
		}
	}
}
