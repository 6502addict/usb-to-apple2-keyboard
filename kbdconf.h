#pragma once

// ── Output mode ───────────────────────────────────────────────────────────────
#define SERIAL         0
#define PARALLEL_A2    1

#define KBD_OUTPUT     PARALLEL_A2

// ── Terminal type ─────────────────────────────────────────────────────────────
#define KBD_TERM       TERM_APPLE2      // TERM_TVI950, TERM_DATANETICS, TERM_APPLE2

// ── Language ──────────────────────────────────────────────────────────────────
#define KBD_LANG       LANG_FR          // LANG_FR, LANG_EN

// ── Serial mode ───────────────────────────────────────────────────────────────
#if KBD_OUTPUT == SERIAL
#define UART_ID        uart0
#define UART_TX_PIN    0
#define UART_RX_PIN    1
#define UART_BAUD      1200
#endif

// ── Parallel Apple II mode ────────────────────────────────────────────────────
#if KBD_OUTPUT == PARALLEL_A2
#define A2_STROBE_PIN        27      // input:  Apple II pulses after key read
#define A2_RESET_PIN         28      // output: reset pulse to Apple II
#define A2_STROBE_PULSE_MS   20      // 25ms pulse   (NE555 pulse ~20ms)
#define A2_RESET_PULSE_MS    20      // 25ms pulse   (NE555 pulse ~20ms)
#endif

