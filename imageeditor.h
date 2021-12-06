#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageEditor; }
QT_END_NAMESPACE

class ImageEditor : public QMainWindow
{
    Q_OBJECT

public:
    ImageEditor(QWidget *parent = nullptr);
    QImage img;
    unsigned char* imgData;
    int width;
    int height;
    int bpp;
    int brightness;
    ~ImageEditor();

private slots:
    void openImage();
    void blurImage();
    void changeBrightness();
    void changeContrast();
    void sharpenImage();
    void enhanceImage();

private:
    Ui::ImageEditor *ui;
};
#endif // IMAGEEDITOR_H
