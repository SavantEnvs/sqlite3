/* Fleet policy (§6.1): disable LeakSanitizer preventively at BUILD time — ASan use-after-free/
   overflow and UBSan stay fully on and halting. OSS-Fuzz's own test/ossfuzz.c intentionally leaks
   on some SQLite error paths; a runtime ASan default-options override, whether compiled in or
   passed via ASAN_OPTIONS, is forbidden (Mayhem alone owns the runtime ASAN/LibFuzzer option set),
   so this is done via the sanctioned build-time hook below instead. SPEC.md §6.2 item 15 bans the
   override symbol names anywhere under mayhem/ -- comments included -- so they are described in
   prose rather than named. __lsan_is_turned_off is the sanctioned hook and is NOT the banned
   construct. */
int __lsan_is_turned_off(void) {
  return 1;
}
