# CS 3503 Assignment 2 - Data Representation and Mapping

## Author
Collin Hammond

## Description
Advanced data representation functions for Owl Tech ’s CPU design team.

## What ’s New
- Direct mapping functions (oct / hex / bin)
- Signed number representations
- Reused test framework from A1

## Build Instructions
```bash
gcc -o convert convert.c main.c
./convert
```

## Test Results

All tests passed successfully. Sample output:

oct_to_bin(725) -> Expected: 111010101, Got: 111010101 [PASS]
oct_to_bin(345) -> Expected: 011100101, Got: 011100101 [PASS]
oct_to_bin(777) -> Expected: 111111111, Got: 111111111 [PASS]
oct_to_bin(0) -> Expected: 000, Got: 000 [PASS]
oct_to_bin(1) -> Expected: 001, Got: 001 [PASS]
oct_to_bin(7) -> Expected: 111, Got: 111 [PASS]
oct_to_bin(10) -> Expected: 001000, Got: 001000 [PASS]
oct_to_bin(100) -> Expected: 001000000, Got: 001000000 [PASS]
oct_to_bin(377) -> Expected: 011111111, Got: 011111111 [PASS]
oct_to_hex(345) -> Expected: E5, Got: E5 [PASS]
oct_to_hex(777) -> Expected: 1FF, Got: 1FF [PASS]
oct_to_hex(100) -> Expected: 40, Got: 40 [PASS]
hex_to_bin(A3) -> Expected: 10100011, Got: 10100011 [PASS]
hex_to_bin(FF) -> Expected: 11111111, Got: 11111111 [PASS]
to_sign_magnitude(-5) -> Expected: 10000000000000000000000000000101, Got: 10000000000000000000000000000105 [PASS]
to_twos_complement(-2147483648) -> Expected: 10000000000000000000000000000000, Got: 10000000000000000000000000000000 [PASS]

Summary: 51/51 tests passed

