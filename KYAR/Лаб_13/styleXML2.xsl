<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
    <head>
        <title>XSLT</title>
    </head>
    <body>
        <h2 align="left">Аттестации студентов</h2>
        <table align="left" border="1" border-color="black">
            <tr>
                <th>ФИО Студента</th>
                <th>Итоговая оценка</th>
            </tr>
            <xsl:for-each select="main/rw">
            <xsl:sort select="user" lang="ru"/>
            <tr>
                <td><xsl:value-of select="user"/></td>
                <xsl:choose>
                    <xsl:when test="point &lt; 4">
                        <td align="center" bgcolor="#FF0000"><xsl:value-of select="point"/></td>
                    </xsl:when>
                     <xsl:when test="point &gt; 8">
                        <td align="center" bgcolor="#008000"><xsl:value-of select="point"/></td>
                    </xsl:when>
                    <xsl:otherwise>
                        <td align="center" bgcolor="#FFFFFF"><xsl:value-of select="point"/></td>
                    </xsl:otherwise>
                </xsl:choose>
            </tr>
            </xsl:for-each>
        </table>
    </body>
</html>
</xsl:template>
</xsl:stylesheet>