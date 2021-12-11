#include "gtest/gtest.h"
#include "Lanter/Communication/CommunicatinFactory.h"

TEST(TestCommunicationFactory, CheckSingleTcpServerCreation) {
    EXPECT_NE(Lanter::Communication::CommunicationFactory::getSingleTcpServer(), nullptr);
}

TEST(TestCommunicationFactory, CheckTCPClient) {
    EXPECT_NE(Lanter::Communication::CommunicationFactory::getTcpClient("127.0.0.1", 20501), nullptr);

    EXPECT_ANY_THROW(Lanter::Communication::CommunicationFactory::getTcpClient("355.355.355.355", 20501));
}

TEST(TestCommunicationFactory, CheckSizeControlDecorator) {
    EXPECT_NE(Lanter::Communication::CommunicationFactory::getSizeControlDecorator(
                                Lanter::Communication::CommunicationFactory::getSingleTcpServer()), nullptr);
}