# RingQt6 - common functions for the Linux/macOS scripts (source this file)
#
# Environment variables (optional):
#   QMAKE        full path to the Qt 6 qmake program
#   RING_QT6_JOBS number of parallel jobs for make
#   RINGQT6_NOGENCODE set it to skip generating the C++ code before building

RINGQT6_DIR="$(cd "$(dirname "${BASH_SOURCE[0]:-$0}")" && pwd)"

ringqt6_os() {
	case "$(uname -s)" in
		Darwin) echo macos ;;
		Linux)  echo linux ;;
		*)      echo unknown ;;
	esac
}

ringqt6_jobs() {
	if [ -n "$RING_QT6_JOBS" ]; then echo "$RING_QT6_JOBS"; return; fi
	if [ "$(ringqt6_os)" = "macos" ]; then sysctl -n hw.ncpu; else nproc 2>/dev/null || echo 2; fi
}

# Set QMAKE to a Qt 6 qmake
ringqt6_find_qmake() {
	local c candidates
	if [ -n "$QMAKE" ] && [ -x "$QMAKE" ]; then
		candidates="$QMAKE"
	else
		candidates="$(command -v qmake6) $(command -v qmake-qt6)"
		if [ "$(ringqt6_os)" = "macos" ] && command -v brew >/dev/null 2>&1; then
			candidates="$candidates $(brew --prefix qt 2>/dev/null)/bin/qmake $(brew --prefix qt@6 2>/dev/null)/bin/qmake"
		fi
		candidates="$candidates /usr/lib/qt6/bin/qmake /usr/lib64/qt6/bin/qmake $(command -v qmake)"
	fi
	for c in $candidates; do
		if [ -x "$c" ] && "$c" -query QT_VERSION 2>/dev/null | grep -q '^6\.'; then
			QMAKE="$c"
			return 0
		fi
	done
	echo "Error: Qt 6 qmake is not found."
	echo "Install Qt 6 first (installdeps_ubuntu_qt6.sh, installdeps_fedora_qt6.sh or installdeps_macos_qt6.sh)"
	echo "or set the QMAKE environment variable to the Qt 6 qmake program."
	return 1
}

# Check that the Ring library (libring.so/libring.dylib) is installed
ringqt6_check_ring() {
	if [ "$(ringqt6_os)" = "macos" ]; then
		[ -f "$RINGQT6_DIR/../../lib/libring.dylib" ] && return 0
		echo "Error: ring/lib/libring.dylib is not found - Build Ring first (language/build/buildclang.sh)"
	else
		[ -f /usr/lib/libring.so ] && return 0
		echo "Error: /usr/lib/libring.so is not found - Build/Install Ring first (language/build/buildgcc.sh)"
		if [ -f "$RINGQT6_DIR/../../lib/libring.so" ]; then
			echo "Tip: sudo ln -s $(cd "$RINGQT6_DIR/../.." && pwd)/lib/libring.so /usr/lib/libring.so"
		fi
	fi
	return 1
}

# Generate the C++ code and the Ring classes for this platform
# (The code in the cpp folder is generated for Windows: it uses ActiveX classes, etc.)
ringqt6_gencode() {
	local script="$1"
	if [ -n "$RINGQT6_NOGENCODE" ]; then return 0; fi
	if [ ! -x "$RINGQT6_DIR/../../bin/ring" ]; then
		echo "Error: ring/bin/ring is not found - Build Ring first"
		return 1
	fi
	echo "Generating the code for this platform ($script)"
	bash "$RINGQT6_DIR/$script" || return 1
}

# ringqt6_build <project.pro> <library name> <build type: gcc|clang> <gencode script>
# Set RINGQT6_NOGENCODE=1 to skip the code generation step
ringqt6_build() {
	local pro="$1" name="$2" kind="$3" gencode="$4" lib ext
	cd "$RINGQT6_DIR" || return 1
	ringqt6_find_qmake || return 1
	ringqt6_check_ring || return 1
	ringqt6_gencode "$gencode" || return 1
	cd "$RINGQT6_DIR" || return 1
	echo "Using $QMAKE (Qt $("$QMAKE" -query QT_VERSION))"
	# The files extracted from the zip may have a modification time in the future
	# (another time zone/clock) - this makes make run qmake again and again
	echo "Updating the files modification time"
	find "$RINGQT6_DIR" -type f -exec touch {} +
	# Clean the previous build (core/light/full use the same folder)
	if [ -f Makefile ]; then make distclean >/dev/null 2>&1; fi
	if [ "$kind" = "clang" ]; then
		"$QMAKE" "$pro" -r -spec macx-clang "CONFIG+=release" || return 1
		ext=dylib
	else
		"$QMAKE" "$pro" "CONFIG+=release" || return 1
		ext=so
	fi
	echo "Building with $(ringqt6_jobs) parallel jobs"
	if ! make -j"$(ringqt6_jobs)"; then
		echo "=== Build failed - running make again (single job) to show the error ==="
		make 2>&1 | grep -E -B3 -A12 "error|Error" | head -150
		return 1
	fi
	lib="lib${name}.${ext}"
	mkdir -p "$RINGQT6_DIR/../../lib"
	cp -L "$lib" "$RINGQT6_DIR/../../lib/" || return 1
	echo "Done: $(cd "$RINGQT6_DIR/../../lib" && pwd)/$lib"
}
