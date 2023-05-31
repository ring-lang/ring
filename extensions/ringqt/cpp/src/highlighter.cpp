/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
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
	File is modified to include Ring Keywords and Ignore the Case
	Updated by : Mahmoud Fayed <msfclipper@yahoo.com>
	Date	    : 2016.09.14
*/

#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    setColors(Qt::darkBlue,Qt::darkMagenta,Qt::red,Qt::darkGreen,Qt::blue);
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    
    setCurrentBlockState(0);
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

void Highlighter::setColors(QColor c1,QColor c2,QColor c3,QColor c4,QColor c5) {

    HighlightingRule rule;
    highlightingRules.remove(0,highlightingRules.count());
    keywordFormat.setForeground(c1);
    if (this->nKeywordsBold)
	    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bagain\\b" << "\\band\\b" << "\\bbut\\b"
                    << "\\bbye\\b" << "\\bcall\\b" << "\\bcase\\b"
                    << "\\bcatch\\b" << "\\bclass\\b" << "\\bdef\\b"
                    << "\\bdo\\b" << "\\bdone\\b" << "\\belse\\b"
                    << "\\belseif\\b" << "\\bend\\b" << "\\bexit\\b"
                    << "\\bfor\\b" << "\\bfrom\\b" << "\\bfunc\\b"
                    << "\\bget\\b" << "\\bgive\\b" << "\\bif\\b"
                    << "\\bimport\\b" << "\\bin\\b" << "\\bload\\b"
                    << "\\bloop\\b" << "\\bnew\\b" << "\\bnext\\b"
					<< "\\bnot\\b" << "\\boff\\b" << "\\bok\\b"
					<< "\\bon\\b" << "\\bor\\b" << "\\bother\\b"
					<< "\\bpackage\\b" << "\\bprivate\\b" << "\\bput\\b"
					<< "\\breturn\\b" << "\\bsee\\b" << "\\bstep\\b"
					<< "\\bswitch\\b" << "\\bto\\b" << "\\btry\\b"
					<< "\\bendfunc\\b" << "\\bendclass\\b" << "\\bendpackage\\b"
					<< "\\bwhile\\b" << "\\bchangeringkeyword\\b"
					<< "\\bendif\\b" << "\\bendfor\\b"
					<< "\\bendwhile\\b" << "\\bendswitch\\b"
					<< "\\bendtry\\b" << "\\bfunction\\b"
					<< "\\bendfunction\\b" << "\\bbreak\\b" << "\\bcontinue\\b"
					<< "\\bchangeringoperator\\b" << "\\bloadsyntax\\b";
                    
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern,Qt::CaseInsensitive);   
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    if (this->nKeywordsBold)
    	classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(c2);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(c5);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(c3);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    rule.pattern = QRegExp("^#+[^\n]*");
    highlightingRules.append(rule);

    rule.pattern = QRegExp("#+( |-|=)[^\n]*");
    highlightingRules.append(rule);
	
    multiLineCommentFormat.setForeground(c3);

    quotationFormat.setForeground(c4);
    rule.pattern = QRegExp("\"(?:(?!\\/\\/).)+\"");
    rule.pattern.setMinimal(true);
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    quotationFormat2.setForeground(c4);
    rule.pattern = QRegExp("\'(?:(?!\\/\\/).)+\'");
    rule.pattern.setMinimal(true);
    rule.format = quotationFormat2;
    highlightingRules.append(rule);

    quotationFormat3.setForeground(c4);
    rule.pattern = QRegExp("`(?:(?!\\/\\/).)+`");
    rule.pattern.setMinimal(true);
    rule.format = quotationFormat3;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("^\\s*/\\*");
    commentEndExpression = QRegExp("\\*/");

}

void Highlighter::setKeywordsBold(int nStatus) {
	this->nKeywordsBold = nStatus;
}
