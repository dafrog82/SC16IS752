#pragma once
#include <Arduino.h>
#include "SC16IS752.h"

/**
 * Класс-обёртка для SC16IS752, позволяющий
 * использовать канал A/B как объект Stream.
 */
class SC16IS752Stream : public Stream {
public:
    SC16IS752Stream(SC16IS752 &sc16, uint8_t channel)
      : sc16is752(sc16), channelID(channel) {}

    int available() override {
        return sc16is752.available(channelID);
    }

    int read() override {
        return sc16is752.read(channelID);
    }

    int peek() override {
        return sc16is752.peek(channelID);
    }

    void flush() override {
        sc16is752.flush(channelID);
    }

    size_t write(uint8_t data) override {
        return sc16is752.write(channelID, data);
    }

    // Разрешаем перегрузки write(const uint8_t*, size_t) и т.п.
    using Print::write;

private:
    SC16IS752 &sc16is752;
    uint8_t    channelID;
};
