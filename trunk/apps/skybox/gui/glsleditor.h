
// Copyright (c) 2011-2012, Daniel M�ller <dm@g4t3.de>
// Computer Graphics Systems Group at the Hasso-Plattner-Institute, Germany
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
//   * Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright 
//     notice, this list of conditions and the following disclaimer in the 
//     documentation and/or other materials provided with the distribution.
//   * Neither the name of the Computer Graphics Systems Group at the 
//     Hasso-Plattner-Institute (HPI), Germany nor the names of its 
//     contributors may be used to endorse or promote products derived from 
//     this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#pragma once
#ifndef __GLSLEDITOR_H__
#define __GLSLEDITOR_H__


#include <QMap>
#include <QWidget>

#include "utils/glsltypes.h"

#include <osg/Shader>

class Ui_GlslEditor;

class QTextDocument;

class ShaderModifier;


class GlslEditor
:    public QWidget
{
    Q_OBJECT

public:
    GlslEditor(QWidget* parent = NULL);
    virtual ~GlslEditor();

    void assign(ShaderModifier *shaderModifier);

    static void wrapped_identifiersChanged(void *object);
    void identifiersChanged();

protected:
    static const e_GlslLanguageType osgShaderTypeToLanguageType(const osg::Shader::Type &type);

    const bool isRegistered(const QString &identifier) const;

    void unregisterIdentiferAndSource(const QString &identifier);
    void registerIdentifierWithSource(
        const QString &identifier
    ,   const QString &source);


signals:

public slots:

protected slots:
    
    void loadShaderFromIdentifier(const QString &identifier);
    void loadNullDocument();

    void documentContentsChanged();

    void on_shaderComboBox_currentIndexChanged(const int index);

    void on_applyPushButton_clicked(bool);
    void on_restorePushButton_clicked(bool);

protected:
    std::auto_ptr<Ui_GlslEditor> m_ui;

    ShaderModifier *m_shaderModifier;

    QMap<QString, QString> m_sourcesByIdentifier;
    QMap<QString, QTextDocument*> m_documentsByIdentifier;

    QMap<QString, bool> m_modifiedByIdentifier;

    QTextDocument *m_activeDocument;
};

#endif // __GLSLEDITOR_H__