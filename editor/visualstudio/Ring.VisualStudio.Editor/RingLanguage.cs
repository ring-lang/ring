using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ring.VisualStudio.TextEditor
{
    class RingLanguage
    {
        #region Member Variables

        private List<string> _comments = new List<string>();
        private List<string> _quoted = new List<string>();
        private List<string> _numeric = new List<string>();
        private List<string> _keyWords = new List<string>();
        private List<string> _identiferTypes = new List<string>();
        private List<string> _custom = new List<string>();

        #endregion

        #region Properties

        public List<string> Comments
        {
            get { return _comments; }
        }
        public List<string> Quoted
        {
            get { return _quoted; }
        }
        public List<string> Numeric
        {
            get { return _numeric; }
        }
        public List<string> KeyWords
        {
            get { return _keyWords; }
        }
        public List<string> IdentifierTypes
        {
            get { return _identiferTypes; }
        }

        #endregion

        #region ctor

        public RingLanguage()
        {
            Initialize();
        }

        #endregion

        #region Methods

        private void Initialize()
        {
            _comments.Add("\\#");
            _comments.Add("\\//");

            _quoted.Add(@"([""'])(?:\\\1|.)*?\1");

            _numeric.Add(@"\b\d+\b");
            _numeric.Add(@"\>");
            _numeric.Add(@"\<");
            _numeric.Add(@"\<\>");
            _numeric.Add(@"\=");
            _numeric.Add(@"\=\=");

            _keyWords.Add(@"\bIF\b");
            _keyWords.Add(@"\bTO\b");
            _keyWords.Add(@"\bOR\b");
            _keyWords.Add(@"\bAND\b");
            _keyWords.Add(@"\bNOT\b");
            _keyWords.Add(@"\bFOR\b");
            _keyWords.Add(@"\bNEW\b");
            _keyWords.Add(@"\bFUNC\b");
            _keyWords.Add(@"\bFROM\b");
            _keyWords.Add(@"\bNEXT\b");
            _keyWords.Add(@"\bLOAD\b");
            _keyWords.Add(@"\bELSE\b");
            _keyWords.Add(@"\bSEE\b");
            _keyWords.Add(@"\bWHILE\b");
            _keyWords.Add(@"\bOK\b");
            _keyWords.Add(@"\bCLASS\b");
            _keyWords.Add(@"\bBREAK\b");
            _keyWords.Add(@"\bRETURN\b");
            _keyWords.Add(@"\bBUT\b");
            _keyWords.Add(@"\bEND\b");
            _keyWords.Add(@"\bGIVE\b");
            _keyWords.Add(@"\bBYE\b");
            _keyWords.Add(@"\bEXIT\b");
            _keyWords.Add(@"\bTRY\b");
            _keyWords.Add(@"\bCATCH\b");
            _keyWords.Add(@"\bDONE\b");
            _keyWords.Add(@"\bSWITCH\b");
            _keyWords.Add(@"\bON\b");
            _keyWords.Add(@"\bOTHER\b");
            _keyWords.Add(@"\bOFF\b");
            _keyWords.Add(@"\bIN\b");
            _keyWords.Add(@"\bLOOP\b");
            _keyWords.Add(@"\bPACKAGE\b");
            _keyWords.Add(@"\bIMPORT\b");
            _keyWords.Add(@"\bPRIVATE\b");
            _keyWords.Add(@"\bSTEP\b");
            _keyWords.Add(@"\bDO\b");
            _keyWords.Add(@"\bAGAIN\b");
            _keyWords.Add(@"\bCALL\b");
            // Types
            //_identiferTypes.Add(@"\bvoid\b");
            //_identiferTypes.Add(@"\bboolean\b");
            //_identiferTypes.Add(@"\binteger\b");
            //_identiferTypes.Add(@"\bfloat\b");
            //_identiferTypes.Add(@"\bdouble\b");
            //_identiferTypes.Add(@"\bstring\b");
            //_identiferTypes.Add(@"\bobject\b");
            //_identiferTypes.Add(@"\binterface\b");
            //_identiferTypes.Add(@"\binvalid\b");
        }

        #endregion
    };
}
