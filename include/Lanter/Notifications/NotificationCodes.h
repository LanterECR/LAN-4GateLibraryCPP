//
// Created by Владимир Лысенков on 30.06.2020.
//

#ifndef LAN_4GATELIBRARYCPP_NOTIFICATIONCODES_H
#define LAN_4GATELIBRARYCPP_NOTIFICATIONCODES_H
namespace Lanter {
    namespace Notifications {
        /// \brief Список поддерживаемых уведомлений
        enum class NotificationCodes {
            NoNotification, ///<
            ReversalUploadingError, ///<
            IncorrectVoidAmount, ///<
            IncorrectRefundAmount, ///<
            PrinterError, ///<
            ReceiptPrintingError, ///<
            PaperOut, ///<
            CurrencyNotSupported, ///<
            Connecting, ///<
            Executing, ///<
            TapOrInsertCard, ///<
            InsertCard, ///<
            EjectCard, ///<
            InsertMagStripe, ///<
            CardReading, ///<
            CardReadingError, ///<
            CardReadingErrorTryAgain, ///<
            CardReadingErrorUseAnother, ///<
            MagStripeReadingError, ///<
            CtlsDeclinedUseChip, ///<
            ChipDeclinedUseMagStripe, ///<
            ReaderError, ///<
            ChipPaymentNotAllowed, ///<
            CtlsPaymentNotAllowed, ///<
            MagStripePaymentNotAllowed, ///<
            FallbackNotAllowed, ///<
            CardBlocked, ///<
            AccountBlocked, ///<
            CardInBlackList, ///<
            DeclinedCardExpired, ///<
            DeclinedSuspectedFraud, ///<
            DeclinedCallAcquirer, ///<
            DeclinedCardRestricted, ///<
            DeclinedCallIssuerBank, ///<
            DeclinedNotAllowedForCard, ///<
            DeclinedNotAllowedForCardholder, ///<
            DeclinedSecurityViolation, ///<
            EnterPin, ///<
            PinEntered, ///<
            OfflinePinEntered, ///<
            IncorrectPinTryAgain, ///<
            OfflinePinBlocked, ///<
            OfflinePinLastTry, ///<
            OfflinePinTryCount, ///<
            DeclinedPinEntryLimitReached, ///<
            DeclinedIncorrectPin, ///<
            CriticalBatteryLevel, ///<
            DangerBatteryLevel, ///<
            ErrorPinMandatory, ///<
            ErrorPinInput, ///<
            MsrDeclinedUseChip, ///<
            PinEntryTimeout, ///<
            QrShowing, ///<
            //Диапазон
            FirstValue = ReversalUploadingError,
            LastValue = QrShowing
        };
    }
}//Lanter
#endif //LAN_4GATELIBRARYCPP_NOTIFICATIONCODES_H
