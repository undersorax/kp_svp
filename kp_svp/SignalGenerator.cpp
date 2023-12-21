#include "SignalGenerator.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QPainter>
#include <QPointF>
#include <cmath>

SignalGenerator::SignalGenerator(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800, 400);
    // Создаем интерфейс для ввода параметров сигнала
    amplitudeEdit = new QLineEdit(this);
    frequencyEdit = new QLineEdit(this);
    phaseShiftEdit = new QLineEdit(this);
    generateButton = new QPushButton("Генерировать и Отобразить", this);
    chartLabel = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout;

    formLayout->addRow("Амплитуда:", amplitudeEdit);
    formLayout->addRow("Частота (Гц):", frequencyEdit);
    formLayout->addRow("Фазовый сдвиг (радианы):", phaseShiftEdit);
    formLayout->addRow(generateButton);
    formLayout->addRow(chartLabel);
    layout->addLayout(formLayout);

    connect(generateButton, &QPushButton::clicked, this, &SignalGenerator::generateSignal);
}

void SignalGenerator::generateSignal()
{
    amplitude = amplitudeEdit->text().toDouble();
    frequency = frequencyEdit->text().toDouble();
    phaseShift = phaseShiftEdit->text().toDouble();
    updateChart();// Обновление данных графика
}

void SignalGenerator::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->width();
    int height = this->height();

    painter.setPen(Qt::blue);

    QPointF previousPoint;
    for (int x = 0; x < width; ++x) {
        double t = static_cast<double>(x) / width;
        double y = amplitude * std::sin(2 * M_PI * frequency * t + phaseShift);
        int yPos = height / 2 + 50 - static_cast<int>(y);

        if (x > 0) {
            painter.drawLine(previousPoint, QPointF(x, yPos));
        }

        previousPoint = QPointF(x, yPos);
    }
}

void SignalGenerator::updateChart()
{
    update();
    chartLabel->setText("Амплитуда: " + QString::number(amplitude) +
                        " Частота (Гц): " + QString::number(frequency) +
                        " Фазовый сдвиг (радианы): " + QString::number(phaseShift));
}
