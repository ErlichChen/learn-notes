# Building Java Application

## Setup

Create a folder for the new project and change directory into it.

```shell
mkdir demo
cd demo
```

## Run the init task

From inside the new project directory, run the init task with the java-application argument.

```shell
gradle init --type java-application
# 1. Select build script DSL.
# 2. Select test framework.
# 3. Project name.
# 4. Source package.
```

## Execute the build

Run the build command. Use regular **gradle** command or **gradlew** script.

```shell
./gradlew build
# or
gradle build

```

## Run the application

Gradle build used the Application plugin, run the application from the command line. use the tasks task to see what task has been added by the plugin.

```shell
gradle tasks
```

**Run** task execute the **main** method in the class assined to the **mainClassName** property.  

```shell
gradle run
```