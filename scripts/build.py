import os
import subprocess

# Paths
project_root = os.path.dirname(os.path.abspath(__file__)) + "/../"
build_dir = os.path.join(project_root, "build")

# Ensure the build directory exists
os.makedirs(build_dir, exist_ok=True)

# Build the project
def build_project():
    print("Starting build process...")
    try:
        # Run the make command in the project root
        subprocess.run(["make", "-C", project_root], check=True)
        print("Build completed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Build failed with error: {e}")
        exit(1)

# Clean the build
def clean_build():
    print("Cleaning build directory...")
    try:
        subprocess.run(["make", "clean", "-C", project_root], check=True)
        print("Clean completed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Clean failed with error: {e}")
        exit(1)

# Main entry point
if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="Build and manage the project.")
    parser.add_argument("--clean", action="store_true", help="Clean the build directory before building.")
    args = parser.parse_args()

    if args.clean:
        clean_build()

    build_project()
