#include <QApplication>
#include "SignalGenerator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SignalGenerator signalGenerator;
    signalGenerator.setWindowTitle("Генератор синусоидального сигнала");
    signalGenerator.resize(800, 400);
    signalGenerator.show();

    return app.exec();
}
