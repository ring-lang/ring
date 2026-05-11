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

import QtQuick 2.0

Rectangle {
    id: root
    width: 320
    height: 480
    color: "lightgray"

    property string locale: view.currentItem.locale

    Text {
        id: title
        text: "Select locale:"
    }

    Rectangle {
        id: chooser
        anchors.top: title.bottom
        anchors.topMargin: 5
        width: parent.width-10
        x: 5
        height: parent.height/2 - 10
        color: "#40300030"
        ListView {
            id: view
            clip: true
            focus: true
            anchors.fill: parent
            model: [
                "en_US",
                "en_GB",
                "fi_FI",
                "de_DE",
                "ar_SA",
                "hi_IN",
                "zh_CN",
                "th_TH",
                "fr_FR",
                "nb_NO",
                "sv_SE"
            ]
            delegate: Text {
                property string locale: modelData
                height: 30
                width: view.width
                text: Qt.locale(modelData).name + " ("+ Qt.locale(modelData).nativeCountryName + "/" + Qt.locale(modelData).nativeLanguageName + ")"
                MouseArea {
                    anchors.fill: parent
                    onClicked: view.currentIndex = index
                }
            }
            highlight: Rectangle {
                height: 30
                color: "#60300030"
            }
        }
    }

    Rectangle {
        color: "white"
        anchors.top: chooser.bottom
        anchors.topMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        x: 5; width: parent.width - 10

        Column {
            anchors.fill: parent
            spacing: 5
            Text {
                property var date: new Date()
                text: "Date: " + date.toLocaleDateString(Qt.locale(root.locale))
            }
            Text {
                property var date: new Date()
                text: "Time: " + date.toLocaleTimeString(Qt.locale(root.locale))
            }
            Text {
                property var dow: Qt.locale(root.locale).firstDayOfWeek
                text: "First day of week: " + Qt.locale(root.locale).standaloneDayName(dow)
            }
            Text {
                property var num: 10023823
                text: "Number: " + num.toLocaleString(Qt.locale(root.locale))
            }
            Text {
                property var num: 10023823
                text: "Currency: " + num.toLocaleCurrencyString(Qt.locale(root.locale))
            }
        }
    }
}
