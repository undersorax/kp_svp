#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class SignalGenerator : public QWidget
{
    Q_OBJECT

public:
    SignalGenerator(QWidget *parent = nullptr);

private slots:
    void generateSignal();

protected:
    void paintEvent(QPaintEvent *event) override;
    void updateChart();

private:
    QLineEdit *amplitudeEdit;
    QLineEdit *frequencyEdit;
    QLineEdit *phaseShiftEdit;
    QPushButton *generateButton;
    QLabel *chartLabel;

    double amplitude = 1.0;
    double frequency = 1.0;
    double phaseShift = 0.0;
};

#endif // SIGNALGENERATOR_H
