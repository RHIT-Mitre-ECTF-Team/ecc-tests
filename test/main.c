// Using BearSSL to perform ECC diffie-hellman key exchange over UART
// tiva c series tm4c123gxl
#include <bearssl.h>
#include "TM4C123.h"
#include "uart.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"

#include "driverlib/eeprom.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

// use NIST P-256 curve from BearSSL
#define CURVE BR_EC_secp256r1

/// Generate ECC key pair
void generate_ecc_key_pair(br_ec_private_key *sk, br_ec_public_key *pk)
{
    br_ec_impl *ec_impl = br_ec_get_default();
    br_ec_keygen skgen = ec_impl->keygen;
    skgen(ec_impl, sk, pk);
}

// Diffie-Hellman key exchange
void dh_key_exchange(br_ec_private_key *sk, br_ec_public_key *pk, br_ec_private_key *sk2, br_ec_public_key *pk2)
{
    br_ec_impl *ec_impl = br_ec_get_default();
    br_ec_compute_shared_key skcomp = ec_impl->mulgen;
    skcomp(ec_impl, sk, pk2, sk2);
}

int main(void)
{
}