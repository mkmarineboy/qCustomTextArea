#include "mktextarea.h"
#include "qquicktextdocument.h"
#include "QtQuick/private/qquicktextdocument_p.h"

MKTextArea::MKTextArea(QQuickItem *parent) : QQuickTextArea(parent)
{
    connect(this,&MKTextArea::implicitWidthChanged,this,&MKTextArea::setLastLineWidth);
    connect(this,&MKTextArea::hoveredChanged,this,&MKTextArea::changeMouseCursor);
}

void MKTextArea::setLastLineWidth()
{
    QQuickTextEditPrivate *d = reinterpret_cast<QQuickTextEditPrivate *>(QQuickTextEdit::d_ptr.data());

    int subLines = 0;
    qreal tLastLineNewWidth{};
    for (QTextBlock it = d->document->begin(); it != d->document->end(); it = it.next()) {
        QTextLayout *layout = it.layout();
        if (!layout)
            continue;
        subLines += layout->lineCount()-1;
        tLastLineNewWidth = layout->lineAt(subLines).naturalTextWidth();
    }
    emit lastLineWidthChanged(tLastLineNewWidth);

    if(lastLineWidth_ != tLastLineNewWidth)
    {
        lastLineWidth_ = tLastLineNewWidth;
        emit lastLineWidthChanged(lastLineWidth_);
    }

}

void MKTextArea::setEnableCursorShape(bool enableCursorShape)
{
    if (enableCursorShape_ == enableCursorShape)
        return;
    enableCursorShape_ = enableCursorShape;
    emit enableCursorShapeChanged(enableCursorShape_);
}

void MKTextArea::changeMouseCursor()
{
    if(enableCursorShape_)
    {
        if(isHovered())
            setCursor(QCursor(Qt::CursorShape::IBeamCursor));
        else
            setCursor(QCursor(Qt::CursorShape::ArrowCursor));
    }
}

qreal MKTextArea::lastLineWidth() const
{
    return lastLineWidth_;
}

bool MKTextArea::enableCursorShape() const
{
    return enableCursorShape_;
}
