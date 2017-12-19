###------------------------------------------------------------
### BitCoin BlockChain -- Ring
### 2017-12-17  Bert Mariani
###
### Based on Savjee's JavaScript  
### https://www.savjee.be/2017/07/Writing-tiny-blockchain-in-JavaScript/
###
### Creates a GenesisCoin, then adds New Coins to the Chain
### Each block includes the previous block hash
### Calculates a hash for the current block
### This insures the validity  of the Chain
###
### Change Proof of Work "difficulty" in Class BlockChain Init() function
###-----------------------------------------------------------------------


# Load Ring Libraries
    Load "guilib.ring"
    Load "stdlib.ring"
	
### Proof of Work - Mining Difficulty -- Number of leading zero in hashCalculation	
### Difficulty 1=>4  2=>120  3=> 6128 4=> 33584

difficulty = 2       

###-----------------------------
### Block - Init-GenesisCoin

    BertBlock = new Block()
#See BertBlock See nl +nl

###------------------------------	
### BlockChain() - GenesisBlock	

    BertChain = new Blockchain()
    #See BertChain.chain  See nl +nl

###------------------------------
### BlockChain-AddBlock

    BertChain.addBlock( new Block() { index="1" timestamp="21/11/2017" 	data="Amount-4"	} )
    #See BertChain.chain  See nl +nl


    BertChain.addBlock( new Block() { index="2" timestamp="22/1/2017" 	data="Amount-8" } )
    #See BertChain.chain  See nl +nl

    BertChain.addBlock( new Block() { index="3" timestamp="23/11/2017" 	data="Amount-6" } )
    See BertChain.chain  See nl +nl   ### ALL blocks in the Chain



See "================= TEST if VALID CHAIN ===================" +nl +nl

See "Len-BertChain.chain "+ len(BertChain.chain) +nl +nl

### Test if Valid Chain

    result = BertChain.isChainValid()
    See "Test isChainValid: "+ result +nl +nl	

### Modify chain - show before and after - test Validity 

    See "Before Change: Block.data" +nl
    See BertChain.chain[3] See nl     ### SPECIFIC block in the Chain

    BertChain.chain[3].data = "Amount-100" 
    See "After Change: Block.data" +nl	
    See BertChain.chain[3] See nl
	
    result = BertChain.isChainValid()
    See "Test isChainValid: "+ result +nl +nl

###============= END OF CODE========================

###============= CLASS BLOCK =======================
### The BLOCK is a list of data ITEMS

class Block

    ### Variables section
    
	index timestamp data previousHash hash nonce='' 
   
    ### Constructor is Init function. Nonce is a loop counter for Proof of Work difficulty.
    
	func init()
      index        = "00"
      timestamp    = "01/01/2001" 
      data         = "Init-GenesisCoin" 
      previousHash = "00"
      hash         =  calculateHash()
	  nonce        = 0
      return self
		
    func calculateHash()
	  calHash = SHA256( index + timestamp + data + previousHash + nonce )
	  return calHash 
	  
	### Proof of Work. Uses difficulty and nonce loop counter. Find hash with leading zeros.
    
	func mineBlock(difficulty) 
	  zeroString = "00000000000000000000000000000000"
	  diffString = left(zeroString, difficulty)
	 
	  while ( left(hash, difficulty) != diffString )
        nonce++
        hash = calculateHash()	
      end
		#See "Difficult "+ difficulty +" Nonce "+ nonce +" "+ left(hash, difficulty) +" Hash " + hash +nl
	  
    return	  

###=============== CLASS BLOCKCHAIN ===================================
### The CHAIN is an array/list of BLOCKS of data
### Difficulty for Proof of Work - Used for number of leading zeros in resulting hash.
### Change "difficulty" inside the Init() function.
	
class Blockchain

    chain = []
	#difficulty = 1                   ### Use Global
    
	func init()
	    chain + createGenesisBlock()
    	#difficulty = 2               ### Use Global
        return chain[ len(chain) ]

    func createGenesisBlock()
      	BlockChainBlk = new Block() { index="0" timestamp="01/01/2017" data="GenesisCoin" previousHash="0"}
        return BlockChainBlk

    func getLatestBlock()
        return chain[len(chain)]

    func addBlock(newBlock)
        newBlock.previousHash = getLatestBlock().hash
        
	   #newBlock.hash  = newBlock.calculateHash() ### Regular hash for block  
		newBlock.mineBlock(difficulty)            ### Difficulty hash for Mining - Proof of Work     
        
		#insert(chain,0,newBlock)                 ### beginning of list
        add(chain, newBlock)                      ### end of list
        return

	
    func isChainValid()   		
        for  i = 2 to len(chain)
			
            currentBlock  = chain[i]
            previousBlock = chain[i - 1]

            if ( currentBlock.hash != currentBlock.calculateHash() ) 
                return "INVALID"
            ok

            if ( currentBlock.previousHash != previousBlock.hash ) 
                return "INVALID"
            ok
        next

        return "VALID"
    
	
###======================================
