#!/bin/sh
set -ex
JS_FILES="d8.js"\
" macros.py"

V8ROOT="${SRCROOT}/.."

SRC_DIR="${V8ROOT}/src"

NATIVE_JS_FILES=""

for i in ${JS_FILES} ; do
  NATIVE_JS_FILES+="${SRC_DIR}/${i} "
done

V8_GENERATED_SOURCES_DIR="${CONFIGURATION_TEMP_DIR}/generated"
mkdir -p "${V8_GENERATED_SOURCES_DIR}"

D8_CC="${V8_GENERATED_SOURCES_DIR}/d8-js.cc"
D8_EMPTY_CC="${V8_GENERATED_SOURCES_DIR}/d8-js-empty.cc"

python "${V8ROOT}/tools/js2c.py" \
  "${D8_CC}.new" \
  "${D8_EMPTY_CC}.new" \
  "D8" \
  ${NATIVE_JS_FILES}

# Only use the new files if they're different from the existing files (if any),
# preserving the existing files' timestamps when there are no changes.  This
# minimizes unnecessary build activity for a no-change build.

if ! diff -q "${D8_CC}.new" "${D8_CC}" >& /dev/null ; then
  mv "${D8_CC}.new" "${D8_CC}"
else
  rm "${D8_CC}.new"
fi

if ! diff -q "${D8_EMPTY_CC}.new" "${D8_EMPTY_CC}" >& /dev/null ; then
  mv "${D8_EMPTY_CC}.new" "${D8_EMPTY_CC}"
else
  rm "${D8_EMPTY_CC}.new"
fi

