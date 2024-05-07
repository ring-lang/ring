/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

/*
	File is modified to be merged with RingQt
	Updated by : Mahmoud Fayed <msfclipper@yahoo.com>
	Date	   : 2017.01.29
*/

#include <QtWidgets>

#include "codeeditor.h"
#include "ring.h"

#include <algorithm> 

CodeEditor::CodeEditor(QWidget *parent, VM *pVM) : GPlainTextEdit(parent,pVM) , c(0)
{
    lineNumberArea = new LineNumberArea(this);
    this->areaColor = Qt::black;
    this->areaBackColor = Qt::cyan;
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));

    updateLineNumberAreaWidth(0);
}

void CodeEditor::setLineNumbersAreaColor(QColor oColor) 
{
    this->areaColor = oColor;
}

void CodeEditor::setLineNumbersAreaBackColor(QColor oColor) 
{
    this->areaBackColor = oColor;
}

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space*2;
}



void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}



void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}



void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{

    QPainter painter(lineNumberArea);

    QFont font = painter.font() ;
    font.setPointSize(fontMetrics().height());
    painter.setFont(font);

    painter.fillRect(event->rect(), this->areaBackColor);


    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(this->areaColor);
            painter.drawText(0, top, lineNumberArea->width(), bottom-top,
                             Qt::AlignCenter, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

void CodeEditor::setCompleter(QCompleter *completer)
{
    if (c) {
        QObject::disconnect(c, 0, this, 0);
	delete c;
    }

    c = completer;

    if (!c)
        return;

    c->setWidget(this);
    c->setCompletionMode(QCompleter::PopupCompletion);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(c, SIGNAL(activated(QString)),
                     this, SLOT(insertCompletion(QString)));
}

QCompleter *CodeEditor::completer() const
{
    return c;
}

void CodeEditor::insertCompletion(const QString& completion)
{
    if (c->widget() != this)
        return;
    QTextCursor tc = textCursor();
    int extra = completion.length() - c->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
}

QString CodeEditor::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}

void CodeEditor::focusInEvent(QFocusEvent *e)
{
    if (c)
        c->setWidget(this);
    GPlainTextEdit::focusInEvent(e);
}

void CodeEditor::keyPressEvent(QKeyEvent *e)
{

	QTextCursor cur ;
	int a ;
	int p ;
	int m ;
	QString str ;
	QStringList list ;
	
	if ( e->key() == Qt::Key_Tab) {
 		cur = textCursor();
		if (strcmp(cur.selectedText().toStdString().c_str(),"") == 0 ) 
		{
			cur.insertText("\t");
			e->accept();
			return;
		}
		blockSignals(true);
    		a = cur.anchor();
    		p = cur.position();
    		cur.setPosition(a);
    		cur.movePosition(QTextCursor::StartOfBlock,QTextCursor::MoveAnchor);
    		a = cur.position();    	
    		cur.setPosition(a);
    		cur.setPosition(p, QTextCursor::KeepAnchor);
    		str = cur.selection().toPlainText();
	    		list = str.split("\n");
	    		for (int i = 0; i < list.count(); i++)
	    			list[i].insert(0,"\t");
  	  		str=list.join("\n");
 	   		cur.removeSelectedText();
   	 		cur.insertText(str);

			if (a < p)
   	 			cur.setPosition(a);
			else 
   	 			cur.setPosition(p);

			if (a > p)
    				cur.setPosition(a+list.count(), QTextCursor::KeepAnchor);
			else 
    				cur.setPosition(p+list.count(), QTextCursor::KeepAnchor);

    			setTextCursor(cur);
			e->accept();
			blockSignals(false);
			return ;		
	}
	else if ( e->key() == Qt::Key_Backtab) {
 		cur = textCursor();
		blockSignals(true);
    		a = cur.anchor();
    		p = cur.position();
    		cur.setPosition(a);
    		cur.movePosition(QTextCursor::StartOfBlock,QTextCursor::MoveAnchor);
    		a = cur.position();    	
    		cur.setPosition(a);
    		cur.setPosition(p, QTextCursor::KeepAnchor);
    		str = cur.selection().toPlainText();
    			list = str.split("\n");
			m = 0;
    			for (int i = 0; i < list.count(); i++) {
				if (list[i][0] == '\t') {
	   	 			list[i] = list[i].right(list[i].count()-1);
					m++;
				}
			}
    			str=list.join("\n");
    			cur.removeSelectedText();
    			cur.insertText(str);

			if (a<p)
    				cur.setPosition(a);
			else 
    				cur.setPosition(p);

			if (a>p)
  				cur.setPosition(a-m, QTextCursor::KeepAnchor);
			else 
				cur.setPosition(p-m, QTextCursor::KeepAnchor);

    			setTextCursor(cur);
			e->accept();
			blockSignals(false);
			return ;
	}

    if (c && c->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
       switch (e->key()) {
       case Qt::Key_Enter:
       case Qt::Key_Return:
		e->ignore();
		return; // let the completer do default behavior
       case Qt::Key_Escape:     
       case Qt::Key_Backtab:
		c->popup()->hide();
		return; // let the completer do default behavior
       default:
           break;
       }
    }

    bool isShortcut = ((e->modifiers() & Qt::ControlModifier) && e->key() == Qt::Key_E); // CTRL+E
    if (!c || !isShortcut) // do not process the shortcut when we have a completer
        GPlainTextEdit::keyPressEvent(e);

    const bool ctrlOrShift = e->modifiers() & (Qt::ControlModifier | Qt::ShiftModifier);
    if (!c || (ctrlOrShift && e->text().isEmpty()))
        return;

    static QString eow("~!#%^&*()+{}|:<>?,/;[]\\-="); // end of word
    bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();

    if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 3
                      || eow.contains(e->text().right(1)))) {
        c->popup()->hide();
        return;
    }

    if (completionPrefix != c->completionPrefix()) {
        c->setCompletionPrefix(completionPrefix);
        c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
    }
    QRect cr = cursorRect();
    cr.setWidth(c->popup()->sizeHintForColumn(0)
                + c->popup()->verticalScrollBar()->sizeHint().width());
    c->complete(cr); // popup it up!
}