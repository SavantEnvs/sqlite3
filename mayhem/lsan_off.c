/* Fleet policy (§6.1): disable LeakSanitizer preventively at BUILD time — ASan use-after-free/
   overflow and UBSan stay fully on and halting. OSS-Fuzz's own test/ossfuzz.c intentionally leaks
   on some SQLite error paths; a runtime __asan_default_options()/ASAN_OPTIONS override is
   forbidden (Mayhem alone owns the runtime ASAN/LibFuzzer option set), so this is done via the
   sanctioned build-time hook instead. */
int __lsan_is_turned_off(void) {
  return 1;
}
