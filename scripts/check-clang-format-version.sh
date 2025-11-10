#!/usr/bin/env bash
set -e

MIN_VERSION_MAJOR=21
MIN_VERSION_MINOR=1

# Try searching for `clang-format`
if ! command -v clang-format >/dev/null 2>&1; then
    echo "Clang-format not found. Please install version >= ${MIN_VERSION_MAJOR}.${MIN_VERSION_MINOR}"
    exit 1
fi

# Get version text, e.g. "clang-format version 1.0.0"
VERSION_STR=$(clang-format --version)

# Separate major and minor numbers
VERSION_NUM=$(echo "$VERSION_STR" | grep -oE '[0-9]+\.[0-9]+' | head -n1)
MAJOR=$(echo "$VERSION_NUM" | cut -d. -f1)
MINOR=$(echo "$VERSION_NUM" | cut -d. -f2)

# Compare version
if [ "$MAJOR" -lt "$MIN_VERSION_MAJOR" ] || \
   { [ "$MAJOR" -eq "$MIN_VERSION_MAJOR" ] && [ "$MINOR" -lt "$MIN_VERSION_MINOR" ]; }; then
    echo "Detected clang-format $VERSION_NUM, but minimum required is ${MIN_VERSION_MAJOR}.${MIN_VERSION_MINOR}+"
    exit 1
fi

echo "Clang-format version $VERSION_NUM OK"
exit 0
