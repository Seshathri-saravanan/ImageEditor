#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked(event);
}

void ClickableLabel::mouseMoveEvent(QMouseEvent* event) {
    emit moved(event);
}

void ClickableLabel::mouseReleaseEvent(QMouseEvent* event) {
    emit released(event);
}
