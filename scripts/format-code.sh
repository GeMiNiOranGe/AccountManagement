#!/usr/bin/env bash
set -e

# Check clang-format version
bash ./scripts/check-clang-format-version.sh || exit 1

# Format code if pass
CHANGED_FILES=$(git diff --cached --name-only -- '*.c' '*.cpp' '*.cc' '*.cxx' '*.h' '*.hpp' '*.hh' '*.hxx')
if [ -n "$CHANGED_FILES" ]; then
    echo "Formatting C++ files..."
    echo "$CHANGED_FILES" | while read file; do
        clang-format -i "$file"
        git add "$file"
    done
fi
