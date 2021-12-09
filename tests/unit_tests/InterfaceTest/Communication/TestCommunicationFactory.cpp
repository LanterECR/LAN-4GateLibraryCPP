#include "gtest/gtest.h"
#include "Lanter/Communication/CommunicatinFactory.h"

TEST(TestCommunicationFactory, CheckSingleTcpServerCreation) {
    ASSERT_NE(Lanter::Communication::CommunicationFactory::getSingleTcpServer(), nullptr);
}

TEST(TestCommunicationFactory, CheckFactory) {
    ASSERT_NE(Lanter::Communication::CommunicationFactory::getSizeControlDecorator(
                                Lanter::Communication::CommunicationFactory::getSingleTcpServer()), nullptr);
}