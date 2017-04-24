using System.ComponentModel.Composition;
using Microsoft.VisualStudio.Text.Classification;
using Microsoft.VisualStudio.Utilities;

namespace Ring.VisualStudio.TextEditor
{
    class RingSyntaxType
    {
        internal static class RingClassificationDefinition
        {
            /// <summary>
            /// Defines the "Ring" classification type.
            /// </summary>
            [Export(typeof(ClassificationTypeDefinition))]
            [Name("Ring")]
            internal static ClassificationTypeDefinition RingType = null;

            [Export(typeof(ClassificationTypeDefinition))]
            [Name("RingNumeric")]
            internal static ClassificationTypeDefinition RingNumericType = null;

            [Export]
            [Name("ring")]
            [BaseDefinition("text")]
            internal static ContentTypeDefinition RingContentDefinition = null;

            [Export]
            [FileExtension(".ring")]
            [ContentType("ring")]
            internal static FileExtensionToContentTypeDefinition
                      RingFileExtensionDefinition = null;
        }
    }
}
