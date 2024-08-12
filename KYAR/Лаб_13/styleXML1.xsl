<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" indent="yes"/>

    <xsl:template match="/">
        <html>
            <head>
                <title>XSLT</title>
                <style type="text/css">
                    .catalog{
                        display: table;
                        border-collapse: collapse;
                        margin: 10px;
                      }
                      
                      .head, .product{
                        display: table-row;
                      }
                      
                      .nname, .nbrand, .ndescription, .nprice{
                        display: table-cell;
                        border: 1px solid black;
                        padding: 5px;
                        text-align: left;
                        background-color: rgb(208, 166, 240);
                      }
                      
                      .name, .brand, .description, .price{
                        display: table-cell;
                        border: 1px solid black;
                        padding: 5px;
                        text-align: left;
                        background-color: rgb(241, 221, 255);
                      }
                </style>
            </head>
            <body>
                <xsl:apply-templates select="catalog">
                    <xsl:sort select="product/price" data-type="number" order="ascending"/>
                </xsl:apply-templates>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="catalog">
        <div class="catalog">
            <div class="head">
                <div class="nname">Название</div>
                <div class="nbrand">Бренд</div>
                <div class="ndescription">Описание</div>
                <div class="nprice">Цена</div>
            </div>
            <xsl:apply-templates select="product">
                <xsl:sort select="number(price)" data-type="number" order="ascending"/>
            </xsl:apply-templates>
        </div>
    </xsl:template>

    <xsl:template match="product">
        <div class="product">
            <div class="name"><xsl:value-of select="name"/></div>
            <div class="brand"><xsl:value-of select="brand"/></div>
            <div class="description"><xsl:value-of select="description"/></div>
            <div class="price"><xsl:value-of select="price"/></div>
        </div>
    </xsl:template>
</xsl:stylesheet>
