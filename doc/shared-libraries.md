Shared Libraries
================

## hellebitconsensus

The purpose of this library is to make the verification functionality that is critical to Hellebit's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `hellebitconsensus.h` located in  `src/script/hellebitconsensus.h`.

#### Version

`hellebitconsensus_version` returns an `unsigned int` with the the API version *(currently at an experimental `0`)*.

#### Script Validation

`hellebitconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `hellebitconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `hellebitconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `hellebitconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/hellebit/bips/blob/master/bip-0016.mediawiki)) subscripts
- `hellebitconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/hellebit/bips/blob/master/bip-0066.mediawiki)) compliance

##### Errors
- `hellebitconsensus_ERR_OK` - No errors with input parameters *(see the return value of `hellebitconsensus_verify_script` for the verification status)*
- `hellebitconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `hellebitconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `hellebitconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`

### Example Implementations
- [NHellebit](https://github.com/NicolasDorier/NHellebit/blob/master/NHellebit/Script.cs#L814) (.NET Bindings)
- [node-libhellebitconsensus](https://github.com/bitpay/node-libhellebitconsensus) (Node.js Bindings)
- [java-libhellebitconsensus](https://github.com/dexX7/java-libhellebitconsensus) (Java Bindings)
- [hellebitconsensus-php](https://github.com/Bit-Wasp/hellebitconsensus-php) (PHP Bindings)
