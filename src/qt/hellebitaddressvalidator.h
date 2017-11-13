// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef HELLEBIT_QT_HELLEBITADDRESSVALIDATOR_H
#define HELLEBIT_QT_HELLEBITADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class HellebitAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit HellebitAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Hellebit address widget validator, checks for a valid hellebit address.
 */
class HellebitAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit HellebitAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // HELLEBIT_QT_HELLEBITADDRESSVALIDATOR_H
