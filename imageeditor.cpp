#include "imageeditor.h"
#include "ui_imageeditor.h"
#include <QImage>
#include <QFileDialog>
ImageEditor::ImageEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageEditor)
{
    ui->setupUi(this);
    brightness =0;
    connect(ui->openImageButton,&QPushButton::clicked,this,&ImageEditor::openImage);
    connect(ui->blurSlider,&QSlider::valueChanged,this,&ImageEditor::blurImage);
    connect(ui->brightnessSlider,&QSlider::valueChanged,this,&ImageEditor::changeBrightness);
    connect(ui->contrastSlider,&QSlider::valueChanged,this,&ImageEditor::changeContrast);
    connect(ui->sharpenRadioButton,&QRadioButton::clicked,this,&ImageEditor::sharpenImage);
    connect(ui->enhanceRadioButton,&QRadioButton::clicked,this,&ImageEditor::enhanceImage);
}

ImageEditor::~ImageEditor()
{
    delete ui;
}

void ImageEditor::openImage(){
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    img.load(fileName);
    ui->imageLabel->setPixmap(QPixmap::fromImage(img));
    ui->imageLabel->setMargin(10);
    //ui->imageLabel->setSi
}


void ImageEditor::blurImage(){
    int width = img.width();
    int height = img.height();
    int kx = ui->blurSlider->value();
    int ky =ui->blurSlider->value();
    QImage blurredImage(img.width(),img.height(),img.format());
    int avgr =0;
    int avgb =0;
    int avgg =0;
    int row_avgr =0;
    int row_avgb =0;
    int row_avgg =0;
    for(int i=-ky;i<=ky;i++){
        for(int j=-kx;j<=kx;j++){
            if(i>=0 && i<height && j>=0 && j<width){
                QColor oldVal(img.pixel(j,i));
                avgr += oldVal.red();
                avgg += oldVal.green();
                avgb += oldVal.blue();
            }

        }
    }
    row_avgb =avgb;
    row_avgg =avgg;
    row_avgr =avgr;
    int np = (2*kx+1)*(2*ky+1);
    for(int y=0;y<height;y++){
        avgr = row_avgr;
        avgb = row_avgb;
        avgg = row_avgg;
        for(int x=0;x<width;x++){
            if(x!=0 || y!=0){
                for(int i=y-ky;i<=y+ky;i++){
                    int oldx = x-kx-1;
                    int newx = x+kx;
                    if(i>=0 && i<height){
                        if(oldx>=0){
                            QColor oldVal(img.pixel(oldx,i));
                            avgr -= oldVal.red();
                            avgb -= oldVal.blue();
                            avgg -= oldVal.green();
                        }
                        if(newx<width){
                            QColor oldVal(img.pixel(newx,i));
                            avgr += oldVal.red();
                            avgb += oldVal.blue();
                            avgg += oldVal.green();
                        }

                    }
                }
            }
            QColor newval(avgr/np,avgg/np,avgb/np);
            blurredImage.setPixel(x,y,newval.rgb());
        }
        for(int i=0;i<=kx;i++){
            if(y+ky<height){
                QColor oldVal(img.pixel(i,y+ky));
                row_avgb += oldVal.blue();
                row_avgg += oldVal.green();
                row_avgr += oldVal.red();
            }
            if(y-ky-1>=0){
                QColor oldVal(img.pixel(i,y-ky-1));
                row_avgb -= oldVal.blue();
                row_avgg -= oldVal.green();
                row_avgr -= oldVal.red();
            }
        }
    }
    ui->imageLabel->setPixmap(QPixmap::fromImage(blurredImage));
    //ui->imageLabel->setPixmap(QPixmap::fromImage(img));
    //ui->imageLabel->setMargin(10);
}

void boundPixelValue(int &x){
    if(x<0)x=0;
    if(x>255)x=255;
}

void ImageEditor::changeBrightness(){
    int width = img.width();
    int height = img.height();
    brightness = ui->brightnessSlider->value();
    QImage newImage(img.width(),img.height(),img.format());
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            QColor oldVal(img.pixel(x,y));
            int red =oldVal.red()+brightness;
            int blue =oldVal.blue()+brightness;
            int green =oldVal.green()+brightness;
            boundPixelValue(red);
            boundPixelValue(blue);
            boundPixelValue(green);
            QColor newval(red,green,blue);
            newImage.setPixel(x,y,newval.rgb());
        }
    }
    ui->imageLabel->setPixmap(QPixmap::fromImage(newImage));
}
void ImageEditor::changeContrast(){
    int width = img.width();
    int height = img.height();
    float contrast = (float)ui->contrastSlider->value()/100;
    QImage newImage(img.width(),img.height(),img.format());
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            QColor oldVal(img.pixel(x,y));
            int red =oldVal.red()*contrast;
            int blue =oldVal.blue()*contrast;
            int green =oldVal.green()*contrast;
            boundPixelValue(red);
            boundPixelValue(blue);
            boundPixelValue(green);
            QColor newval(red,green,blue);
            newImage.setPixel(x,y,newval.rgb());
        }
    }
    ui->imageLabel->setPixmap(QPixmap::fromImage(newImage));
}

void ImageEditor::sharpenImage(){
    int width = img.width();
    int height = img.height();
    //float contrast = (float)ui->contrastSlider->value()/100;
    QImage newImage(img.width(),img.height(),img.format());
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            QColor oldVal(img.pixel(x,y));
            int red =oldVal.red()*5;
            int blue =oldVal.blue()*5;
            int green =oldVal.green()*5;
            if(x-1>=0){
                QColor oldVal(img.pixel(x-1,y));
                red -= oldVal.red();
                green -= oldVal.green();
                blue -= oldVal.blue();
            }
            if(y+1<height){
                QColor oldVal(img.pixel(x,y+1));
                red -= oldVal.red();
                green -= oldVal.green();
                blue -= oldVal.blue();
            }
            if(x+1<width){
                QColor oldVal(img.pixel(x+1,y));
                red -= oldVal.red();
                green -= oldVal.green();
                blue -= oldVal.blue();
            }
            if(y-1>=0){
                QColor oldVal(img.pixel(x,y-1));
                red -= oldVal.red();
                green -= oldVal.green();
                blue -= oldVal.blue();
            }
            boundPixelValue(red);
            boundPixelValue(blue);
            boundPixelValue(green);
            QColor newval(red,green,blue);
            newImage.setPixel(x,y,newval.rgb());
        }
    }
    ui->imageLabel->setPixmap(QPixmap::fromImage(newImage));
}


void ImageEditor::enhanceImage(){
    int width = img.width();
    int height = img.height();
    //float contrast = (float)ui->contrastSlider->value()/100;
    QImage newImage(img.width(),img.height(),img.format());
    std::vector<int>freqr(256,0);
    std::vector<int>freqb(256,0);
    std::vector<int>freqg(256,0);
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            QColor oldVal(img.pixel(x,y));
            int red =oldVal.red();
            int blue =oldVal.blue();
            int green =oldVal.green();
            freqr[red]++;
            freqb[blue]++;
            freqg[green]++;
        }
    }
    std::vector<int>mapr(256,0);
    std::vector<int>mapb(256,0);
    std::vector<int>mapg(256,0);
    int cumr=0,cumb=0,cumg=0;
    int total = height*width;
    for(int i=0;i<256;i++){
        cumr += freqr[i];
        cumb += freqb[i];
        cumg += freqg[i];
        mapr[i] = (255*cumr)/total;
        mapg[i] = (255*cumg)/total;
        mapb[i] = (255*cumb)/total;
    }
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            QColor oldVal(img.pixel(x,y));
            int red =mapr[oldVal.red()];
            int blue =mapb[oldVal.blue()];
            int green =mapg[oldVal.green()];
            QColor newval(red,green,blue);
            newImage.setPixel(x,y,newval.rgb());
        }
    }
    ui->imageLabel->setPixmap(QPixmap::fromImage(newImage));
}
