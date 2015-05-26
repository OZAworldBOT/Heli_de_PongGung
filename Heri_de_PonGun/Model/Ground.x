xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 67;
 -3500.00000;0.00000;-3500.00000;,
 -2500.00000;0.00000;-3500.00000;,
 -2500.00000;0.00000;-2500.00000;,
 -3500.00000;0.00000;-2500.00000;,
 -1500.00000;0.00000;-3500.00000;,
 -1500.00000;0.00000;-2500.00000;,
 -500.00000;0.00000;-3500.00000;,
 -500.00000;0.00000;-2500.00000;,
 500.00000;0.00000;-3500.00000;,
 500.00000;0.00000;-2500.00000;,
 1500.00000;0.00000;-3500.00000;,
 1500.00000;0.00000;-2500.00000;,
 2500.00000;0.00000;-3500.00000;,
 2500.00000;0.00000;-2500.00000;,
 3500.00000;0.00000;-3500.00000;,
 3500.00000;0.00000;-2500.00000;,
 -2500.00000;0.00000;-1500.00000;,
 -3500.00000;0.00000;-1500.00000;,
 -1500.00000;0.00000;-1500.00000;,
 -500.00000;0.00000;-1500.00000;,
 500.00000;0.00000;-1500.00000;,
 1500.00000;0.00000;-1500.00000;,
 2500.00000;0.00000;-1500.00000;,
 3500.00000;0.00000;-1500.00000;,
 -2500.00000;0.00000;-500.00000;,
 -3500.00000;0.00000;-500.00000;,
 -1500.00000;0.00000;-500.00000;,
 -500.00000;0.00000;-500.00000;,
 500.00000;0.00000;-500.00000;,
 1500.00000;0.00000;-500.00000;,
 2500.00000;0.00000;-500.00000;,
 3500.00000;0.00000;-500.00000;,
 -2500.00000;0.00000;500.00000;,
 -3500.00000;0.00000;500.00000;,
 -1500.00000;0.00000;500.00000;,
 -500.00000;0.00000;500.00000;,
 -500.00000;0.00000;-500.00000;,
 500.00000;0.00000;500.00000;,
 -500.00000;0.00000;500.00000;,
 1500.00000;0.00000;500.00000;,
 500.00000;0.00000;500.00000;,
 2500.00000;0.00000;500.00000;,
 3500.00000;0.00000;500.00000;,
 -2500.00000;0.00000;1500.00000;,
 -3500.00000;0.00000;1500.00000;,
 -1500.00000;0.00000;1500.00000;,
 -500.00000;0.00000;1500.00000;,
 500.00000;0.00000;1500.00000;,
 1500.00000;0.00000;1500.00000;,
 2500.00000;0.00000;1500.00000;,
 3500.00000;0.00000;1500.00000;,
 -2500.00000;0.00000;2500.00000;,
 -3500.00000;0.00000;2500.00000;,
 -1500.00000;0.00000;2500.00000;,
 -500.00000;0.00000;2500.00000;,
 500.00000;0.00000;2500.00000;,
 1500.00000;0.00000;2500.00000;,
 2500.00000;0.00000;2500.00000;,
 3500.00000;0.00000;2500.00000;,
 -2500.00000;0.00000;3500.00000;,
 -3500.00000;0.00000;3500.00000;,
 -1500.00000;0.00000;3500.00000;,
 -500.00000;0.00000;3500.00000;,
 500.00000;0.00000;3500.00000;,
 1500.00000;0.00000;3500.00000;,
 2500.00000;0.00000;3500.00000;,
 3500.00000;0.00000;3500.00000;;
 
 49;
 4;3,2,1,0;,
 4;2,5,4,1;,
 4;5,7,6,4;,
 4;7,9,8,6;,
 4;9,11,10,8;,
 4;11,13,12,10;,
 4;13,15,14,12;,
 4;17,16,2,3;,
 4;16,18,5,2;,
 4;18,19,7,5;,
 4;19,20,9,7;,
 4;20,21,11,9;,
 4;21,22,13,11;,
 4;22,23,15,13;,
 4;25,24,16,17;,
 4;24,26,18,16;,
 4;26,27,19,18;,
 4;27,28,20,19;,
 4;28,29,21,20;,
 4;29,30,22,21;,
 4;30,31,23,22;,
 4;33,32,24,25;,
 4;32,34,26,24;,
 4;34,35,27,26;,
 4;38,37,28,36;,
 4;40,39,29,28;,
 4;39,41,30,29;,
 4;41,42,31,30;,
 4;44,43,32,33;,
 4;43,45,34,32;,
 4;45,46,35,34;,
 4;46,47,40,35;,
 4;47,48,39,40;,
 4;48,49,41,39;,
 4;49,50,42,41;,
 4;52,51,43,44;,
 4;51,53,45,43;,
 4;53,54,46,45;,
 4;54,55,47,46;,
 4;55,56,48,47;,
 4;56,57,49,48;,
 4;57,58,50,49;,
 4;60,59,51,52;,
 4;59,61,53,51;,
 4;61,62,54,53;,
 4;62,63,55,54;,
 4;63,64,56,55;,
 4;64,65,57,56;,
 4;65,66,58,57;;
 
 MeshMaterialList {
  2;
  49;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   14.000000;
   0.370000;0.370000;0.370000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Field.bmp";
   }
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   15.000000;
   0.270000;0.270000;0.270000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Sand.bmp";
   }
  }
 }
 MeshTextureCoords {
  67;
  -8.000000;-6.000000;
  -6.000000;-6.000000;
  -6.000000;-4.000000;
  -8.000000;-4.000000;
  -4.000000;-6.000000;
  -4.000000;-4.000000;
  -2.000000;-6.000000;
  -2.000000;-4.000000;
  0.000000;-6.000000;
  0.000000;-4.000000;
  2.000000;-6.000000;
  2.000000;-4.000000;
  4.000000;-6.000000;
  4.000000;-4.000000;
  6.000000;-6.000000;
  6.000000;-4.000000;
  -6.000000;-2.000000;
  -8.000000;-2.000000;
  -4.000000;-2.000000;
  -2.000000;-2.000000;
  0.000000;-2.000000;
  2.000000;-2.000000;
  4.000000;-2.000000;
  6.000000;-2.000000;
  -6.000000;0.000000;
  -8.000000;0.000000;
  -4.000000;0.000000;
  -2.000000;0.000000;
  0.000000;0.000000;
  2.000000;0.000000;
  4.000000;0.000000;
  6.000000;0.000000;
  -6.000000;2.000000;
  -8.000000;2.000000;
  -4.000000;2.000000;
  -2.000000;2.000000;
  -1.000000;0.000000;
  0.000000;1.000000;
  -1.000000;1.000000;
  2.000000;2.000000;
  0.000000;2.000000;
  4.000000;2.000000;
  6.000000;2.000000;
  -6.000000;4.000000;
  -8.000000;4.000000;
  -4.000000;4.000000;
  -2.000000;4.000000;
  0.000000;4.000000;
  2.000000;4.000000;
  4.000000;4.000000;
  6.000000;4.000000;
  -6.000000;6.000000;
  -8.000000;6.000000;
  -4.000000;6.000000;
  -2.000000;6.000000;
  0.000000;6.000000;
  2.000000;6.000000;
  4.000000;6.000000;
  6.000000;6.000000;
  -6.000000;8.000000;
  -8.000000;8.000000;
  -4.000000;8.000000;
  -2.000000;8.000000;
  0.000000;8.000000;
  2.000000;8.000000;
  4.000000;8.000000;
  6.000000;8.000000;;
 }
}