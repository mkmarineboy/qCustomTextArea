#ifndef MKTEXTAREA_H
#define MKTEXTAREA_H

#include <QObject>
#include <QtQuickTemplates2/private/qquicktextarea_p_p.h>

class MKTextArea : public QQuickTextArea
{
    Q_OBJECT
    Q_PROPERTY(qreal lastLineWidth READ lastLineWidth NOTIFY lastLineWidthChanged)
    Q_PROPERTY(bool enableCursorShape READ enableCursorShape WRITE setEnableCursorShape NOTIFY enableCursorShapeChanged)

public:
    explicit MKTextArea(QQuickItem *parent = nullptr);

    qreal lastLineWidth() const;
    bool enableCursorShape() const;

Q_SIGNALS:
    void lastLineWidthChanged(qreal setLastLineWidth);
    void enableCursorShapeChanged(bool enableCursorShape);

public slots:
    void setLastLineWidth();
    void setEnableCursorShape(bool enableCursorShape);

private slots:
    void changeMouseCursor();

private:
    qreal lastLineWidth_{};
    bool enableCursorShape_{false};
};

#endif // MKTEXTAREA_H
