//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or MGeometryList to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MUniformParameter
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MUniformParameter)
//
// MUniformParameter describes a single uniform hardware shader parameter.
//
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES

#ifndef _MUniformParameter
#define _MUniformParameter

#include <maya/MTypes.h>
#include <maya/MString.h>
#include <maya/MPlug.h>
class MUniform;
class MGeometryList;

// *****************************************************************************

// CLASS DECLARATION (MUniformParameter)

/// Uniform parameter. (OpenMayaRender) (OpenMayaRender.py)
/**
An MUniformParameter describes a single uniform hardware shader parameter. 
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYARENDER_EXPORT MUniformParameter
{
public:

	///
	typedef enum
	{
		///
		kTypeUnknown,

		///
		kTypeBool,

		///
		kTypeInt,

		///
		kTypeFloat,

		///
		kType1DTexture,

		///
		kType2DTexture,

		///
		kType3DTexture,

		///
		kTypeCubeTexture,

		///
		kTypeEnvTexture,

		///
		kTypeString,

		// NOTE - when editing this, be sure to update the internal equivalent
	} DataType;


	typedef enum
	{
		///
		kSemanticUnknown,

		///
		kSemanticObjectDir,		

		///
		kSemanticWorldDir,		

		///
		kSemanticViewDir,		

		///
		kSemanticProjectionDir,	

		///
		kSemanticObjectPos,

		///
		kSemanticWorldPos,	

		///
		kSemanticViewPos,		

		///
		kSemanticProjectionPos,	

		///
		kSemanticColor,

		///
		kSemanticNormal,

		///
		kSemanticBump,

		///
		kSemanticEnvironment,

		///
		kSemanticWorldMatrix,

		///
		kSemanticWorldInverseMatrix,

		///
		kSemanticWorldInverseTransposeMatrix,

		///
		kSemanticViewMatrix,

		///
		kSemanticViewInverseMatrix,

		///
		kSemanticViewInverseTransposeMatrix,

		///
		kSemanticProjectionMatrix,

		///
		kSemanticProjectionInverseMatrix,

		///
		kSemanticProjectionInverseTransposeMatrix,

		///
		kSemanticWorldViewMatrix,

		///
		kSemanticWorldViewInverseMatrix,

		///
		kSemanticWorldViewInverseTransposeMatrix,

		///
		kSemanticWorldViewProjectionMatrix,

		///
		kSemanticWorldViewProjectionInverseMatrix,

		///
		kSemanticWorldViewProjectionInverseTransposeMatrix,

		///
		kSemanticColorTexture,

		///
		kSemanticNormalTexture,

		///
		kSemanticBumpTexture,

		///
		kSemanticNormalizationTexture,

		///
		kSemanticTime,

		// NOTE - when editing this, be sure to update the internal equivalent
	} DataSemantic;

	///
	MUniformParameter();

	///
	MUniformParameter( const MString& name, 
						DataType type, 
						DataSemantic semantic,
						unsigned int numRows = 1,
						unsigned int numColumns = 1,
						void* userData = NULL);

	///
	~MUniformParameter();

	///
	const MUniformParameter& operator=( const MUniformParameter& other);

	///
	const MString&	name() const;

	///
	MUniformParameter::DataType type() const;

	///
	MUniformParameter::DataSemantic semantic() const;

	///
	unsigned int numRows() const;

	///
	unsigned int numColumns() const;

	///
	unsigned int numElements() const;

	///
	void* userData() const;

	///
	bool isATexture() const;

	///
	bool hasChanged( const MGeometryList& iterator) const;

	///
	const float* getAsFloatArray( const MGeometryList& iterator) const;

	///
	void setAsFloatArray( const float* value, unsigned int maxElements) const;

	///
	float getAsFloat( const MGeometryList& iterator) const;

	///
	void setAsFloat( float value) const;

	///
	MString getAsString( const MGeometryList& iterator) const;

	///
	void setAsString( const MString& value) const;

	///
	bool getAsBool( const MGeometryList& iterator) const;

	///
	void setAsBool( bool value) const;

	///
	int getAsInt( const MGeometryList& iterator) const;

	///
	void setAsInt( int value) const;
	
	///
	MPlug getSource() const;

	///
	void setDirty();

protected:

	MUniformParameter( void* ptr);

	void*			_ptr; 

private:
// No private members

	friend class MUniformParameterList;
};



#endif
#endif // _MUniformParameter
